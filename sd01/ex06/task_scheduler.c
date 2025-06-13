#include "task_scheduler.h"

struct ScheduleResult *schedule_tasks(struct TaskList *tasks)
{
	struct TaskProfile *profile = NULL;
	struct PriorityMap *priorities = NULL;
	struct ScheduleResult *result = NULL;
	int core_count = 0;
	int task_id = 0;

	profile = profile_tasks(tasks);
	if (profile == NULL)
		return NULL;
	priorities = compute_priorities_mock(profile);
	if (priorities == NULL)
	{
		free_task_profile(profile);
		return NULL;
	}
	core_count = get_available_core_count();
	if (core_count <= 0)
	{
		free_priority_map(priorities);
		free_task_profile(profile);
		return NULL;
	}
	result = create_schedule_result(core_count);
	if (result == NULL)
	{
		free_priority_map(priorities);
		free_task_profile(profile);
		return NULL;
	}
	for (int i = 0; i < core_count; i++)
	{
		task_id = select_best_task(profile);
		if (task_id < 0)
			break;
		update_schedule_entry(result, i, task_id);
	}
	free_priority_map(priorities);
	free_task_profile(profile);
	return (result);
}
