// Minimal Watchface v2 by szala - 2016
// Includes battery status, showing estimated number of remaining days
// Changed battery lifetime style and date format in this version

#include <pebble.h>

Window *window;
BitmapLayer *white_layer, *line_one, *line_two, *line_three, *line_four, *line_five, *line_six;
BitmapLayer *day_one, *day_two, *day_three, *day_four, *day_five, *day_six, *day_seven;
BitmapLayer *box_one, *box_two, *box_three, *box_four, *box_five, *box_six, *box_seven;
//BitmapLayer *days_layer;
TextLayer *hour_layer, *minute_layer, *date_layer;
GFont custom_font_49;

char buffer[] = "00", buffer2[] = "00", buffer3[] = "Xxx 00 Xxx";

void tick_handler(struct tm *tick_time, TimeUnits units_changed)
{
	// Format the buffer string using tick_time as the time source
	strftime(buffer, sizeof("00"), "%H", tick_time);
	strftime(buffer2, sizeof("00"), "%M", tick_time);
	strftime(buffer3, sizeof("Xxx 00 Xxx"), "%b %e %a", tick_time);

	// Show hour, minute, and date
	text_layer_set_text(hour_layer, buffer);
	text_layer_set_text(minute_layer, buffer2);
	text_layer_set_text(date_layer, buffer3);
//	text_layer_set_text(hour_layer, "23");
//	text_layer_set_text(minute_layer, "45");
//	text_layer_set_text(date_layer, "May 29 Wed");
}

void battery_handler(BatteryChargeState state) {
	bitmap_layer_set_background_color(day_one,   GColorClear);
	bitmap_layer_set_background_color(day_two,   GColorClear);
	bitmap_layer_set_background_color(day_three, GColorClear);
	bitmap_layer_set_background_color(day_four,  GColorClear);
	bitmap_layer_set_background_color(day_five,  GColorClear);
	bitmap_layer_set_background_color(day_six,   GColorClear);
	bitmap_layer_set_background_color(day_seven, GColorClear);

	static int battery_level;
	battery_level = state.charge_percent;
	battery_level = 50;

	switch(battery_level){
		case 90 :
			bitmap_layer_set_background_color(day_seven, GColorBlack);
			break;
		case 80 :
			bitmap_layer_set_background_color(day_seven, GColorBlack);
			break;
		case 70 :
			bitmap_layer_set_background_color(day_six,   GColorBlack);
			bitmap_layer_set_background_color(day_seven, GColorBlack);
			break;
		case 60 :
			bitmap_layer_set_background_color(day_five,  GColorBlack);
			bitmap_layer_set_background_color(day_six,   GColorBlack);
			bitmap_layer_set_background_color(day_seven, GColorBlack);
			break;
		case 50 :
			bitmap_layer_set_background_color(day_five,  GColorBlack);
			bitmap_layer_set_background_color(day_six,   GColorBlack);
			bitmap_layer_set_background_color(day_seven, GColorBlack);
			break;
		case 40 :
			bitmap_layer_set_background_color(day_four,  GColorBlack);
			bitmap_layer_set_background_color(day_five,  GColorBlack);
			bitmap_layer_set_background_color(day_six,   GColorBlack);
			bitmap_layer_set_background_color(day_seven, GColorBlack);
			break;
		case 30 :
			bitmap_layer_set_background_color(day_three, GColorBlack);
			bitmap_layer_set_background_color(day_four,  GColorBlack);
			bitmap_layer_set_background_color(day_five,  GColorBlack);
			bitmap_layer_set_background_color(day_six,   GColorBlack);
			bitmap_layer_set_background_color(day_seven, GColorBlack);
			break;
		case 20 :
			bitmap_layer_set_background_color(day_two,   GColorBlack);
			bitmap_layer_set_background_color(day_three, GColorBlack);
			bitmap_layer_set_background_color(day_four,  GColorBlack);
			bitmap_layer_set_background_color(day_five,  GColorBlack);
			bitmap_layer_set_background_color(day_six,   GColorBlack);
			bitmap_layer_set_background_color(day_seven, GColorBlack);
			break;
		case 10 :
			bitmap_layer_set_background_color(day_two,   GColorBlack);
			bitmap_layer_set_background_color(day_three, GColorBlack);
			bitmap_layer_set_background_color(day_four,  GColorBlack);
			bitmap_layer_set_background_color(day_five,  GColorBlack);
			bitmap_layer_set_background_color(day_six,   GColorBlack);
			bitmap_layer_set_background_color(day_seven, GColorBlack);
			break;
		case 0 :
			bitmap_layer_set_background_color(day_one,   GColorBlack);
			bitmap_layer_set_background_color(day_two,   GColorBlack);
			bitmap_layer_set_background_color(day_three, GColorBlack);
			bitmap_layer_set_background_color(day_four,  GColorBlack);
			bitmap_layer_set_background_color(day_five,  GColorBlack);
			bitmap_layer_set_background_color(day_six,   GColorBlack);
			bitmap_layer_set_background_color(day_seven, GColorBlack);
			break;
	}
}

void window_load(Window *window) {
	// Main window
	window_set_background_color(window, GColorBlack);

	// White layer
	white_layer = bitmap_layer_create(GRect(0, 0, 144, 10));
	bitmap_layer_set_background_color(white_layer, GColorWhite);
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(white_layer));

	// Line layers
	line_one = bitmap_layer_create(GRect(18, 0, 3, 10));
	line_two = bitmap_layer_create(GRect(39, 0, 3, 10));
	line_three = bitmap_layer_create(GRect(60, 0, 3, 10));
	line_four = bitmap_layer_create(GRect(81, 0, 3, 10));
	line_five = bitmap_layer_create(GRect(102, 0, 3, 10));
	line_six = bitmap_layer_create(GRect(123, 0, 3, 10));
	bitmap_layer_set_background_color(line_one, GColorBlack);
	bitmap_layer_set_background_color(line_two, GColorBlack);
	bitmap_layer_set_background_color(line_three, GColorBlack);
	bitmap_layer_set_background_color(line_four, GColorBlack);
	bitmap_layer_set_background_color(line_five, GColorBlack);
	bitmap_layer_set_background_color(line_six, GColorBlack);
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(line_one));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(line_two));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(line_three));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(line_four));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(line_five));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(line_six));
	
	// Cell layers
	box_one = bitmap_layer_create(GRect(0, 3, 15, 7));
	box_two = bitmap_layer_create(GRect(21, 3, 15, 7));
	box_three = bitmap_layer_create(GRect(42, 3, 15, 7));
	box_four = bitmap_layer_create(GRect(63, 3, 15, 7));
	box_five = bitmap_layer_create(GRect(84, 3, 15, 7));
	box_six = bitmap_layer_create(GRect(105, 3, 15, 7));
	box_seven = bitmap_layer_create(GRect(126, 3, 15, 7));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(box_one));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(box_two));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(box_three));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(box_four));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(box_five));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(box_six));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(box_seven));
	bitmap_layer_set_background_color(box_one,   GColorBlack);
	bitmap_layer_set_background_color(box_two,   GColorBlack);
	bitmap_layer_set_background_color(box_three, GColorBlack);
	bitmap_layer_set_background_color(box_four,  GColorBlack);
	bitmap_layer_set_background_color(box_five,  GColorBlack);
	bitmap_layer_set_background_color(box_six,   GColorBlack);
	bitmap_layer_set_background_color(box_seven, GColorBlack);

	// Day layers
	day_one = bitmap_layer_create(GRect(0, 3, 18, 7));
	day_two = bitmap_layer_create(GRect(21, 3, 18, 7));
	day_three = bitmap_layer_create(GRect(42, 3, 18, 7));
	day_four = bitmap_layer_create(GRect(63, 3, 18, 7));
	day_five = bitmap_layer_create(GRect(84, 3, 18, 7));
	day_six = bitmap_layer_create(GRect(105, 3, 18, 7));
	day_seven = bitmap_layer_create(GRect(126, 3, 18, 7));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(day_one));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(day_two));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(day_three));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(day_four));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(day_five));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(day_six));
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(day_seven));

	// Hour layer
	hour_layer = text_layer_create(GRect(0, 25, 144, 50));
	text_layer_set_background_color(hour_layer, GColorClear);
	text_layer_set_text_color(hour_layer, GColorWhite);
//	text_layer_set_font(hour_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
	text_layer_set_font(hour_layer, fonts_get_system_font(FONT_KEY_ROBOTO_BOLD_SUBSET_49));
	text_layer_set_text_alignment(hour_layer, GTextAlignmentCenter);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(hour_layer));
	
	// Minute layer
//	minute_layer = text_layer_create(GRect(0, 61, 144, 50));
	minute_layer = text_layer_create(GRect(0, 65, 144, 50));
	text_layer_set_background_color(minute_layer, GColorClear);
	text_layer_set_text_color(minute_layer, GColorWhite);
//	text_layer_set_font(minute_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_LIGHT));
	custom_font_49 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_ROBOTO_LIGHT_SUBSET_49));
	text_layer_set_font(minute_layer, custom_font_49);
	text_layer_set_text_alignment(minute_layer, GTextAlignmentCenter);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(minute_layer));
	
	// Date layer
//	date_layer = text_layer_create(GRect(0, 110, 144, 25));
	date_layer = text_layer_create(GRect(0, 120, 144, 25));
	text_layer_set_background_color(date_layer, GColorClear);
	text_layer_set_text_color(date_layer, GColorWhite);
	text_layer_set_font(date_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
	text_layer_set_text_alignment(date_layer, GTextAlignmentCenter);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(date_layer));

	// Get a time structure so that the face doesn't start blank
	time_t temp = time(NULL);
	struct tm *t = localtime(&temp);

	// Manually call the tick handler when the window is loading
	tick_handler(t, MINUTE_UNIT);

	// Get the current battery level
	battery_handler(battery_state_service_peek());
}
 
void window_unload(Window *window) {
	// We will safely destroy the window's elements here
	bitmap_layer_destroy(white_layer);
	bitmap_layer_destroy(line_one);
	bitmap_layer_destroy(line_two);
	bitmap_layer_destroy(line_three);
	bitmap_layer_destroy(line_four);
	bitmap_layer_destroy(line_five);
	bitmap_layer_destroy(line_six);
//	bitmap_layer_destroy(day_one);
	text_layer_destroy(hour_layer);
	text_layer_destroy(minute_layer);
	text_layer_destroy(date_layer);
	fonts_unload_custom_font(custom_font_49);
}
 
void init() {
	// Initialize the app elements here
	window = window_create();
	window_set_window_handlers(window, (WindowHandlers) {
		.load = window_load,
		.unload = window_unload,
	});

	// Subscribe to services
	tick_timer_service_subscribe(MINUTE_UNIT, (TickHandler) tick_handler);
//	tick_timer_service_subscribe(SECOND_UNIT, (TickHandler) tick_handler);
	battery_state_service_subscribe(battery_handler);
	window_stack_push(window, true);
}
 
void deinit() {
	// De-initialize elements here to save memory
	tick_timer_service_unsubscribe();
	battery_state_service_unsubscribe();
	window_destroy(window);
}
 
int main(void) {
	init();
	app_event_loop();
	deinit();
}