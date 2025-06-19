#include "task_scheduler.h"
static struct TaskProfile *prepare_profile(struct TaskList *tasks)
{
	struct TaskProfile *profile = profile_tasks(tasks);
	return profile;
}

static struct PriorityMap *prepare_priorities(struct TaskProfile *profile)
{
	struct PriorityMap *priorities = compute_priorities_mock(profile);
	return priorities;
}

static int prepare_core_count(void)
{
	return get_available_core_count();
}

static struct ScheduleResult *prepare_schedule_result(int core_count)
{
	return create_schedule_result(core_count);
}

static void assign_tasks_to_cores(struct ScheduleResult *result, struct TaskProfile *profile, int core_count)
{
	int task_id;
	for (int i = 0; i < core_count; i++)
	{
		task_id = select_best_task(profile);
		if (task_id < 0)
			break;
		update_schedule_entry(result, i, task_id);
	}
}

struct ScheduleResult *schedule_tasks(struct TaskList *tasks)
{
	struct TaskProfile *profile = NULL;
	struct PriorityMap *priorities = NULL;
	struct ScheduleResult *result = NULL;
	int core_count = 0;

	profile = prepare_profile(tasks);
	if (profile == NULL)
		return NULL;
	priorities = prepare_priorities(profile);
	if (priorities == NULL)
	{
		free_task_profile(profile);
		return NULL;
	}
	core_count = prepare_core_count();
	if (core_count <= 0)
	{
		free_priority_map(priorities);
		free_task_profile(profile);
		return NULL;
	}
	result = prepare_schedule_result(core_count);
	if (result == NULL)
	{
		free_priority_map(priorities);
		free_task_profile(profile);
		return NULL;
	}
	assign_tasks_to_cores(result, profile, core_count);
	free_priority_map(priorities);
	free_task_profile(profile);
	return (result);
}
