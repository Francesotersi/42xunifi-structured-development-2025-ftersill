#include "workout_shedule.h"

struct WorkoutPlan *create_workout_schedule(char *username)
{
	struct WorkoutPlan *base_plan = NULL;
	struct UserData *new_user = get_user_data(username);
	if (!new_user)
		return (NULL);
	if (base_plan)
		base_plan = refine_plan(base_plan, new_user);
	else
	{
		base_plan = build_base_plan(new_user);
		if (!base_plan)
			return (NULL);
	}
	if (determine_duration(base_plan) <= 0)
	{
		free_workout_plan(base_plan);
		return (NULL);
	}
	for (int day = 0; day < determine_duration(base_plan); day++)
	{
		assign_daily_exercises(base_plan, day);
		assign_daily_tips(base_plan, day);
	}
	free_user_data(new_user);
	return (base_plan);
}
