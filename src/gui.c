/*
  GPL
  (c) 2018, thorsten.johannvorderbrueggen@t-online.de

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

#include "common.h"


/*
 * main window
 */
static GtkWidget *window;
static GtkWidget *vbox;
static GtkWidget *hbox;
static GtkWidget *statusbar;


/*
 * the "rest"
 */
static GtkTooltips *tooltips;


static gboolean
on_delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
	(void) widget;
        (void) event;
	(void) data;

	/*
	  - return FALSE -> "destroy" signal will be sent
	  - return TRUE  -> NO "destroy" signal will be sent
	*/

	GtkWidget *dialog;
	dialog = gtk_message_dialog_new(GTK_WINDOW(window),
					GTK_DIALOG_DESTROY_WITH_PARENT,
					GTK_MESSAGE_QUESTION,
					GTK_BUTTONS_YES_NO,
					_("Are you sure to quit?"));
	gtk_window_set_title(GTK_WINDOW(dialog), "Question");

	gint result = gtk_dialog_run(GTK_DIALOG (dialog));
	gtk_widget_destroy(dialog);

	if (result == GTK_RESPONSE_YES)
		return FALSE;
	else
		return TRUE;
}

static void
exit_function(GtkWidget *widget, gpointer data)
{
	/*
	  For (possible) autosave ...

	  Quit-Button and Quit-Function(s) do autosave
	  via "X" of the wm-window will send "delete-event" which will be handeld
	  dialog box (see on_delete_event@gui.c)
	 */

	(void) widget;
	(void) data;
}


static void
build_help_window(void)
{
	/* the help window */
}

static void
about_button(GtkWidget *widget, gpointer data)
{
	(void) widget;
	(void) data;

	/* about dialog -> http://zetcode.com/gui/gtk2/gtkdialogs/*/
}

void
build_main_window(void)
{
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(window), program_name);

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_name(GTK_WINDOW (window), program_name);

	/*
	 * delete-event -> event coming from the window manager
	 */
	g_signal_connect(window, "delete-event",
			 G_CALLBACK(on_delete_event), NULL);
	g_signal_connect(window, "destroy",
			 G_CALLBACK(gtk_main_quit), NULL);


	/*
	   Layout:
	      +-------------------------------+
	      + ------------- vbox -----------+
	      |           |                   |
	      |           |                   |
	      | buttonbox |    textarea       |   <- hbox for buttonbox + area
	      |           |   (see below)     |
	      |           |                   |
	      +-----------+-------------------+
	      |      ..... statusbar ....     |   <- statusbar
	      +-------------------------------+
	*/

        // ------------------ tooltips --------------------
	tooltips = gtk_tooltips_new();



	// ------------------ statusbar -------------------
	statusbar = gtk_statusbar_new();
	gtk_box_pack_start(GTK_BOX(vbox), statusbar, FALSE, TRUE, 1);

	gtk_widget_show_all(window);



	gtk_widget_show_all(window);
}
