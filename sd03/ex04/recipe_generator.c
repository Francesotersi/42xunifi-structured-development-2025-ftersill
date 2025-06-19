#include "recipe_generator.h"

struct Recipe *create_custom_recipe(void)
{
	struct Recipe *recipe = NULL;
	struct TasteProfile *taste = NULL;
	struct Ingredients *ingredients = get_current_ingredients();

	if (ingredients == NULL)
		return (NULL);
	taste = get_user_taste_profile();
	if (taste == NULL)
	{
		free_ingredients(ingredients);
		return (NULL);
	}
	while (1)
	{
		recipe = create_recipe(ingredients, taste);
		if (recipe == NULL)
		{
			free_ingredients(ingredients);
			free_taste_profile(taste);
			return (NULL);
		}
		if (get_user_approval(recipe) == 1)
		{
			free_taste_profile(taste);
			break ;
		}
	}
	return (recipe);
}
