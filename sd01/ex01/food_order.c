#include "food_order.h"

int process_food_order(struct OrderRequest *request)
{
	if (check_restaurant_status(request) == 0)
		return (-1);
	struct OrderConfirmation *confirmation = create_standard_confirmation();
	if (confirmation == NULL)
	{
		confirmation = create_preorder_confirmation();
		if (confirmation == NULL)
			return (-1);
	}
	send_confirmation_notification(confirmation);
	return (0);
}
