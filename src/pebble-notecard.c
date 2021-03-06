#include <pebble.h>
#include "pebble-notecard.h"

Window* window;
TextLayer* text_layer;
MenuLayer* menu_layer;
card** all_cards;
int i=-1;

card* make_card(char* ques, char* ans)
{
    card* qcard = (card*)malloc(sizeof(card));
    memcpy(qcard->question, ques, strlen(ques));
    memcpy(qcard->answer, ans, strlen(ans));
    return qcard;
}

void make_all_cards()
{
    all_cards = (card**)malloc(3*sizeof(card**));
    all_cards[0] = make_card("Blue Eyes White Dragon", "A friendly but misunderstood dragon that is over-used by Kaiba");
    all_cards[1] = make_card("Dark Magician", "Yugi's favourite guy. Also dark as heck");
    all_cards[2] = make_card("Garfield", "A fat cat.");
}


void up_single_click_handler(ClickRecognizerRef recognizer, 
    void *context)
{
    text_layer_set_text(text_layer, all_cards[i]->question);
}

void down_single_click_handler(ClickRecognizerRef recognizer, 
    void *context)
{
    text_layer_set_text(text_layer, all_cards[i]->answer);
}

void select_single_click_handler(ClickRecognizerRef recognizer, 
    void *context)
{
    text_layer_set_text(text_layer, all_cards[++i]->question);
}

void config_provider(Window* window)
{

    //single click
    
    window_single_click_subscribe(BUTTON_ID_DOWN, 
        down_single_click_handler);
    window_single_click_subscribe(BUTTON_ID_UP, 
        up_single_click_handler);
    window_single_click_subscribe(BUTTON_ID_SELECT, 
        select_single_click_handler);
}

void init()
{

    make_all_cards();
         
    //Create the Window
    window = window_create();
    
    //associate a click config provider with window
    window_set_click_config_provider(window, 
        (ClickConfigProvider) config_provider);

    //Create the Textlayer, for display at (0,0),
    //and with a size of 144 x 40
    text_layer = text_layer_create(GRect(0,0,144,40));
    
    //Set the text that the TextLayer will display
    text_layer_set_text(text_layer, 
        "Welcome to Pebble Notecard!");
    
    //Add as child layer to be included in rendering
    layer_add_child(window_get_root_layer(window),
                    text_layer_get_layer(text_layer));
    
    //Push to the stack, animated
    window_stack_push(window, true);
}

void deinit()
{
    
    //Destroy the text layer
    text_layer_destroy(text_layer);
    
    //Destroy the Window
    window_destroy(window);

}

int main(void) 
{
    
    //Initialize the app
    init();
    
    //Wait for app events
    app_event_loop();
    
    //Deinitialize the app
    deinit();
    
    return 0;
}


