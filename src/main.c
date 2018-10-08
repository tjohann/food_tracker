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

//static char *program_name;

void
build_main_window(void);

static void
__attribute__((noreturn)) usage(int status)
{
	putchar('\n');
	fprintf(stdout, _("Usage: %s [options]              \n"), program_name);
	fprintf(stdout, _("Options:                                       \n"));

	fprintf(stdout, _("        -h                 \
show help                                             \n"));
	fprintf(stdout, _("        -a                 \
argument a                      \n"));
	fprintf(stdout, _("        -s                 \
argument s  \n"));
	putchar('\n');

	exit(status);
}

static void
cleanup(void)
{
	fprintf(stdout, _("Finalize cleanup -> cheers %s\n"), getenv("USER"));
}


int
main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE, LOCALEDIR);
	textdomain(PACKAGE);

	int c;
	while ((c = getopt(argc, argv, "hasd:")) != -1) {
		switch (c) {
		case 'a':
			printf("Argument a\n");
			break;
		case 's':
			printf("Argument s\n");
			break;
		case 'h':
			usage(EXIT_SUCCESS);
			break;
		default:
			fprintf(stderr, _("ERROR: no valid argument\n"));
			usage(EXIT_FAILURE);
		}
	}

	if (atexit(cleanup) != 0)
		exit(EXIT_FAILURE);

	/*
         * init gtk stuff
         */
        gdk_threads_init();
        gdk_threads_enter();

        gtk_init(&argc, &argv);
        build_main_window();

	gtk_main();
        gdk_threads_leave();

	return EXIT_SUCCESS;
}
