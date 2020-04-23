#include <stdio.h>
#include <gtk/gtk.h>
#include <stdarg.h>
#include "words.h"

GtkApplication *app;
GtkWidget *app_window;
GtkWidget *open_bin_window;
GdkCursor *cursor_default;
GMenu *app_menu;
char **word;

struct widgets_langages {
} wl;
const int size_wl = 0;

static gboolean open_bin_window_delete_event_cb ( GtkWidget *widget, GdkEvent *event, gpointer data ) {
	gtk_widget_hide ( open_bin_window );
	return TRUE;
}

static gboolean app_window_delete_event_cb ( GtkWidget *widget, GdkEvent *event, gpointer data ) {
	g_application_quit ( ( GApplication * ) app );
	exit ( EXIT_SUCCESS );
	return FALSE;
}

static void action_open_bin_cb ( GSimpleAction *action, GVariant *parameter, gpointer data ) {
	gtk_widget_show_all ( open_bin_window );
}

static void action_show_settings_cb ( GSimpleAction *action, GVariant *parameter, gpointer data ) {
}

const GActionEntry entries[] = {
	{ "action_open_bin", action_open_bin_cb, NULL, NULL, NULL },
	{ "action_settings", action_show_settings_cb, NULL, NULL, NULL }
};

static void create_actions ( GtkWindow *window ) {
	g_action_map_add_action_entries ( ( GActionMap * ) window, entries, G_N_ELEMENTS ( entries ), NULL );
}

static void create_app_menu ( ) {
	int index = 0;
	g_menu_append ( app_menu, word[0], "win.action_open_bin" );
	g_menu_append ( app_menu, word[1], "win.action_settings" );

}

static void switch_language_cb ( ) {
	g_menu_remove_all ( app_menu );
	create_app_menu ( );
}

GtkWidget *box_select_bin_0;
static void elf_intel_linux_read ( ) {
}
static void pe_intel_windows_read ( ) {
}
static void bin_intel_read ( ) {
}

struct select_items {
	GtkWidget *widget;
	GtkWidget *text_view;
	GtkWidget *box;
} si[3];
int count_si = 0;

GtkWidget *scroll_items_0;

static gboolean text_view_info_bin_draw_cb ( GtkWidget *widget, cairo_t *cr, gpointer data ) {
        gtk_widget_queue_resize ( widget );
        return FALSE;
}

static gboolean open_bin_window_event_cb ( GtkWidget *widget, GdkEvent *event, gpointer data ) {
	printf ( "window\n" );
	GdkEventType type = event->type;
	int active_button = 0;
	switch ( type ) {
		case GDK_BUTTON_PRESS:
			{
			printf ( "window button\n" );
				GtkAllocation al;
				GtkAllocation sal;
				gdouble x = ( ( GdkEventButton * ) event )->x;
				gdouble y = ( ( GdkEventButton * ) event )->y;
				for ( int i = 0; i < count_si; i++ ) {
					int in = 0;
					gtk_widget_get_allocation ( si[i].widget, &al );
					gtk_widget_get_allocation ( scroll_items_0, &sal );
					if ( x >= sal.x && x <= sal.x + sal.width ) {
						if ( y >= sal.y && y <= sal.y + sal.height ) {
							in = 1;
						}
					}
					if ( !in ) break;
					if ( x >= al.x && x <= al.x + al.width ) {
						if ( y >= al.y && y <= al.y + al.height ) {
							gtk_widget_set_name ( si[i].text_view, "info_bin_selected" );
							gtk_widget_set_name ( si[i].widget, "item_bin_selected" );
						}
						else
						{
							gtk_widget_set_name ( si[i].text_view, "info_bin" );
							gtk_widget_set_name ( si[i].widget, "item_bin" );
						}
					}
					else
					{
						gtk_widget_set_name ( si[i].text_view, "info_bin" );
						gtk_widget_set_name ( si[i].widget, "item_bin" );
					}
				}
			}
			break;
		default:
			{
			}
	}
	return FALSE;
}
static gboolean	text_view_item_select_bin_enter_notify_event_cb ( GtkWidget *widget, GdkEvent *event, gpointer data ) {
	printf ( "text_view enter\n" );
	return TRUE;
}

static gboolean text_view_item_select_bin_button_press_event_cb ( GtkWidget *widget, GdkEvent *event, gpointer data ) {
	printf ( "text_view button press\n" );
	GdkEventType type = event->type;
	switch ( type ) {
		case GDK_BUTTON_PRESS:
			{
				for ( int i = 0; i < count_si; i++ ) {
					if ( si[i].text_view == widget ) {
						gtk_widget_set_name ( si[i].text_view, "info_bin_selected" );
						gtk_widget_set_name ( si[i].widget, "item_bin_selected" );
					}
					else {
						gtk_widget_set_name ( si[i].text_view, "info_bin" );
						gtk_widget_set_name ( si[i].widget, "item_bin" );
					}
				}
			}
			break;
		default:
			{
				return FALSE;
			}
	}
	return TRUE;
}

static gboolean text_view_item_select_bin_event_cb ( GtkWidget *widget, GdkEvent *event, gpointer data ) {
	printf ( "text_view event\n" );
	GdkEventType type = event->type;
	switch ( type ) {
		case GDK_BUTTON_PRESS:
			{
				for ( int i = 0; i < count_si; i++ ) {
					if ( si[i].text_view == widget ) {
						gtk_widget_set_name ( si[i].text_view, "info_bin_selected" );
						gtk_widget_set_name ( si[i].widget, "item_bin_selected" );
					}
					else {
						gtk_widget_set_name ( si[i].text_view, "info_bin" );
						gtk_widget_set_name ( si[i].widget, "item_bin" );
					}
				}
			}
			break;
		default:
			{
				GdkWindow *win = gtk_widget_get_window ( widget );
				gdk_window_set_cursor ( win, cursor_default );
				return FALSE;
			}
	}
	GdkWindow *win = gtk_widget_get_window ( widget );
	gdk_window_set_cursor ( win, cursor_default );
	return TRUE;
}

static void add_item ( GtkWidget *box_items, const char *label, const char *info, void (*func) (void), const int count, ... ) {
	GtkWidget *frame_main = g_object_new ( GTK_TYPE_FRAME, "shadow-type", GTK_SHADOW_NONE, "name", "item_bin", NULL );

	GtkWidget *frame_label = g_object_new ( GTK_TYPE_FRAME, "shadow-type", GTK_SHADOW_NONE, "name", "item_label", NULL );
	gtk_widget_set_size_request ( frame_label, 64, 64 );

	gtk_widget_set_margin_start ( frame_label, 5 );
	gtk_widget_set_margin_end ( frame_label, 5 );
	gtk_widget_set_margin_top ( frame_label, 5 );
	gtk_widget_set_margin_bottom ( frame_label, 5 );

	GtkWidget *label_label = gtk_label_new ( label );
	gtk_widget_set_name ( label_label, "label_bin" );

	gtk_widget_set_margin_start ( label_label, 14 );
	gtk_widget_set_margin_end ( label_label, 14 );
	gtk_widget_set_margin_top ( label_label, 14 );
	gtk_widget_set_margin_bottom ( label_label, 14 );

	gtk_container_add ( ( GtkContainer * ) frame_label, label_label );

	GtkWidget *main_box = gtk_box_new ( GTK_ORIENTATION_HORIZONTAL, 0 );
	gtk_container_add ( ( GtkContainer * ) frame_main, main_box );

	gtk_box_pack_start ( ( GtkBox * ) main_box, frame_label, FALSE, FALSE, 0 );

	GtkWidget *box_cpu = gtk_box_new ( GTK_ORIENTATION_HORIZONTAL, 5 );
	gtk_widget_set_margin_start ( box_cpu, 4 );
	gtk_widget_set_margin_end ( box_cpu, 4 );
	gtk_widget_set_margin_top ( box_cpu, 4 );
	gtk_widget_set_margin_bottom ( box_cpu, 4 );

	va_list ap;
	va_start ( ap, count );
	for ( int i = 0; i < count; i++ ) {
		char *l = va_arg ( ap, char * );
		GtkWidget *label_cpu = gtk_label_new ( l );
		gtk_widget_set_name ( label_cpu, "label_cpu" );

		gtk_widget_set_margin_start ( label_cpu, 4 );
		gtk_widget_set_margin_end ( label_cpu, 4 );
		gtk_widget_set_margin_top ( label_cpu, 2 );
		gtk_widget_set_margin_bottom ( label_cpu, 2 );

		GtkWidget *fr = g_object_new ( GTK_TYPE_FRAME, "shadow-type", GTK_SHADOW_NONE, "name", "item_cpu", NULL );
		gtk_container_add ( ( GtkContainer * ) fr, label_cpu );

		gtk_box_pack_end ( ( GtkBox * ) box_cpu, fr, FALSE, FALSE, 0 );
	}
	va_end ( ap );

	GtkWidget *box_2 = gtk_box_new ( GTK_ORIENTATION_VERTICAL, 0 );
	gtk_box_pack_start ( ( GtkBox * ) box_2, box_cpu, FALSE, FALSE, 0 );

	gtk_box_pack_end ( ( GtkBox * ) main_box, box_2, TRUE, TRUE, 0 );


	GtkTextBuffer *buffer = gtk_text_buffer_new ( NULL );
	gtk_text_buffer_set_text ( buffer, info, strlen ( info ) );

	GtkWidget *text_view = gtk_text_view_new_with_buffer ( buffer );
	gtk_widget_set_events ( text_view, GDK_ENTER_NOTIFY_MASK | GDK_BUTTON_PRESS_MASK );
	gtk_text_view_set_cursor_visible ( ( GtkTextView * ) text_view, FALSE );

	gtk_widget_set_margin_start ( text_view, 0 );
	gtk_widget_set_margin_end ( text_view, 0 );
	gtk_widget_set_margin_top ( text_view, 0 );
	gtk_widget_set_margin_bottom ( text_view, 0 );
	gtk_text_view_set_wrap_mode ( ( GtkTextView * ) text_view, GTK_WRAP_WORD );
	gtk_text_view_set_editable ( ( GtkTextView * ) text_view, FALSE );
	gtk_widget_set_name ( text_view, "info_bin" );
	g_signal_connect ( text_view, "draw", G_CALLBACK ( text_view_info_bin_draw_cb ), NULL );

	GtkWidget *frame_text = g_object_new ( GTK_TYPE_FRAME, "shadow-type", GTK_SHADOW_NONE, "name", "text_info", NULL );
	gtk_container_add ( ( GtkContainer * ) frame_text, text_view );
	gtk_widget_set_margin_top ( frame_text, 4 );
	gtk_widget_set_margin_end ( frame_text, 4 );
	gtk_widget_set_margin_start ( frame_text, 4 );
	gtk_widget_set_margin_bottom ( frame_text, 4 );

	GtkWidget *box_info = gtk_box_new ( GTK_ORIENTATION_HORIZONTAL, 0 );
	gtk_box_pack_start ( ( GtkBox * ) box_info, frame_text, TRUE, TRUE, 0 );
	gtk_box_pack_start ( ( GtkBox * ) box_2, box_info, TRUE, TRUE, 0 );

	gtk_box_pack_start ( ( GtkBox * ) box_items, frame_main, FALSE, FALSE, 0 );

	g_signal_connect ( text_view, "enter-notify-event", G_CALLBACK ( text_view_item_select_bin_enter_notify_event_cb ), NULL );
//	g_signal_connect ( text_view, "event", G_CALLBACK ( text_view_item_select_bin_event_cb ), NULL );
	g_signal_connect ( text_view, "button-press-event", G_CALLBACK ( text_view_item_select_bin_button_press_event_cb ), NULL );
	si[count_si].widget = frame_main;
	si[count_si].text_view = text_view;
	count_si++;

}

static void init_open_bin_window ( GtkWindow *window ) {
	gtk_widget_set_name ( ( GtkWidget * ) window, "window_open_bin" );
	gtk_application_window_set_show_menubar ( ( GtkApplicationWindow * ) window, FALSE );
	gtk_window_set_default_size ( window, 600, 600 );
	g_signal_connect ( open_bin_window, "delete-event", G_CALLBACK ( open_bin_window_delete_event_cb ), NULL );

	box_select_bin_0 = gtk_box_new ( GTK_ORIENTATION_VERTICAL, 10 );
	GtkWidget *box_items_0 = gtk_box_new ( GTK_ORIENTATION_VERTICAL, 8 );
	scroll_items_0 = gtk_scrolled_window_new ( NULL, NULL );
	gtk_widget_set_margin_start ( scroll_items_0, 32 );
	gtk_widget_set_margin_end ( scroll_items_0, 32 );
	gtk_widget_set_margin_top ( scroll_items_0, 32 );
	gtk_widget_set_margin_bottom ( scroll_items_0, 32 );

	gtk_widget_set_margin_start ( box_items_0, 10 );
	gtk_widget_set_margin_end ( box_items_0, 10 );
	gtk_widget_set_margin_top ( box_items_0, 10 );
	gtk_widget_set_margin_bottom ( box_items_0, 10 );

	add_item ( box_items_0, "ELF", "Выберите формат файлов предназначенных для линукс", elf_intel_linux_read, 2, "intel", "amd" );
	add_item ( box_items_0, "PE", "Выберите формат файлов предназначенных для windows", pe_intel_windows_read, 2, "intel", "amd" );
	add_item ( box_items_0, "BIN", "Выберите формат файлов не для ос", bin_intel_read, 2, "intel", "amd" );

	gtk_container_add ( ( GtkContainer * ) scroll_items_0, box_items_0 );

	gtk_box_pack_start ( ( GtkBox * ) box_select_bin_0, scroll_items_0, TRUE, TRUE, 0 );

	GtkWidget *button_next_0 = gtk_button_new_with_label ( word[7] );
	GtkWidget *box_buttons_0 = gtk_box_new ( GTK_ORIENTATION_HORIZONTAL, 0 );
	gtk_widget_set_margin_start ( box_buttons_0, 8 );
	gtk_widget_set_margin_end ( box_buttons_0, 8 );
	gtk_widget_set_margin_top ( box_buttons_0, 8 );
	gtk_widget_set_margin_bottom ( box_buttons_0, 8 );
	gtk_box_pack_end ( ( GtkBox * ) box_buttons_0, button_next_0, FALSE, FALSE, 0 );

	gtk_box_pack_end ( ( GtkBox * ) box_select_bin_0, box_buttons_0, FALSE, FALSE, 0 );
	
	gtk_container_add ( ( GtkContainer * ) open_bin_window, box_select_bin_0 );
	g_signal_connect ( open_bin_window, "event", G_CALLBACK ( open_bin_window_event_cb ), NULL );
	gtk_widget_hide ( open_bin_window );
}

const char *style = "window#window_open_bin { } frame#item_bin { background: #5c5c5c; border-radius: 6px; border-color: #000000; box-shadow: 0 0 10px rgba ( 0, 0, 0, 0.8 ); } frame#item_label { background-color: #3c3c3c; border-radius: 6px; border-color: #000000; } label#label_bin { color: #ffff00; } frame#item_cpu { background-color: #ff0000; border-radius: 10px; } label#label_cpu { font-size: 8pt; color: #ffffff; } textview#info_bin * { color: #ffffff; background-color: #5c5c5c; } textview#info_bin_selected * { color: #ffffff; background-color: #4c4c4c; } frame#text_info { background-color: #5c5c5c; } frame#item_bin_selected { background: #4c4c4c; border-radius: 6px; border-color: #000000; box-shadow: 0 0 10px rgba ( 0, 0, 0, 0.8 ); } button:hover { background: #4c4c4c; color: #ffffff; border-radius: 6px; } button { border-radius: 6px; }";
GtkTreeStore *store_dynamic;

enum {
	DYNAMIC_ADDRESS,
	DYNAMIC_OPCODE,
	DYNAMIC_OPERATOR,
	DYNAMIC_COMMENTS,
	DYNAMIC_COUNT
};

static void get_store_dynamic ( GtkWidget *tree_static_view ) {
	store_dynamic = gtk_tree_store_new ( DYNAMIC_COUNT,
			G_TYPE_LONG,
			G_TYPE_STRING,
			G_TYPE_STRING,
			G_TYPE_STRING
			);

	GtkTreeViewColumn *column;
	GtkCellRenderer *renderer;

	const char *cells[] = {
		word[2],
		word[3],
		word[4],
		word[5]
	};

	for ( int i = 0; i < DYNAMIC_COUNT; i++ ) {
		renderer = gtk_cell_renderer_text_new ( );
		column = gtk_tree_view_column_new_with_attributes ( cells[i], renderer, "text", i, NULL );
		gtk_tree_view_column_set_resizable ( column, TRUE );
		gtk_tree_view_append_column ( ( GtkTreeView * ) tree_static_view, column );
	}

	gtk_tree_view_set_model ( ( GtkTreeView * ) tree_static_view, ( GtkTreeModel * ) store_dynamic );
}

static void app_activate_cb ( GApplication *application, gpointer data ) {

	app_window = gtk_application_window_new ( app );
	gtk_window_set_default_size ( ( GtkWindow * ) app_window, 1024, 600 );

	GdkDisplay *display = gdk_display_get_default ( );
	GdkScreen *screen = gdk_display_get_default_screen ( display );
	GtkCssProvider *css_provider = gtk_css_provider_new ( );

	cursor_default = gdk_cursor_new_for_display ( display, GDK_TOP_LEFT_ARROW );

	open_bin_window = gtk_application_window_new ( app );
	init_open_bin_window ( ( GtkWindow * ) open_bin_window );
	create_actions ( ( GtkWindow * ) app_window );
	app_menu = g_menu_new ( );
	create_app_menu ( );

	g_signal_connect ( app_window, "delete-event", G_CALLBACK ( app_window_delete_event_cb ), NULL );

	gtk_application_set_app_menu ( app, ( GMenuModel * ) app_menu );

	GtkWidget *header_bar = gtk_header_bar_new ( );
	gtk_header_bar_set_title ( ( GtkHeaderBar * ) header_bar, "cfdbg" );
	gtk_header_bar_set_show_close_button ( ( GtkHeaderBar * ) header_bar, TRUE );
	gtk_header_bar_set_decoration_layout ( ( GtkHeaderBar * ) header_bar, ":menu,minimize,maximize,close" );
	gtk_window_set_titlebar ( ( GtkWindow * ) app_window, header_bar );


	gtk_style_context_add_provider_for_screen ( screen, ( GtkStyleProvider * ) css_provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION );
	gtk_css_provider_load_from_data ( css_provider, style, strlen ( style ), NULL );

	GtkStyleContext *style_context = gtk_style_context_new ( );
	gtk_style_context_add_provider ( style_context, ( GtkStyleProvider * ) css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER );

	GtkWidget *tree_dynamic_view = gtk_tree_view_new ( );

	get_store_dynamic ( tree_dynamic_view );

	GtkWidget *debug_dynamic_scroll = gtk_scrolled_window_new ( NULL, NULL );
	gtk_container_add ( ( GtkContainer * ) debug_dynamic_scroll, tree_dynamic_view );

	GtkWidget *dynamic_main_box = gtk_box_new ( GTK_ORIENTATION_VERTICAL, 0 );
	GtkWidget *dynamic_component_box = gtk_box_new ( GTK_ORIENTATION_HORIZONTAL, 0 );

	gtk_box_pack_start ( ( GtkBox * ) dynamic_component_box, debug_dynamic_scroll, TRUE, TRUE, 0 );
	gtk_box_pack_start ( ( GtkBox * ) dynamic_main_box, dynamic_component_box, FALSE, FALSE, 0 );

	GtkWidget *app_notebook = gtk_notebook_new ( );
	gtk_notebook_append_page ( ( GtkNotebook * ) app_notebook, dynamic_main_box, gtk_label_new ( word[6] ) );

	gtk_container_add ( ( GtkContainer * ) app_window, app_notebook );
	gtk_widget_show_all ( app_window );
}

int main ( int argc, char **argv ) {
	word = calloc ( 0, sizeof ( char * ) );
	init_words ( );

	app = gtk_application_new ( "com.xverizex.cfdbg", G_APPLICATION_FLAGS_NONE );
	g_application_register ( ( GApplication * ) app, NULL, NULL );
	g_signal_connect ( app, "activate", G_CALLBACK ( app_activate_cb ), NULL );
	return g_application_run ( ( GApplication * ) app, argc, argv );
}
