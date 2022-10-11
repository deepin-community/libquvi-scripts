/* libquvi-scripts
 * Copyright (C) 2013  Toni Gundogdu <legatvs@gmail.com>
 *
 * This file is part of libquvi-scripts <http://quvi.sourceforge.net>.
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General
 * Public License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include "config.h"

#include <string.h>
#include <glib.h>
#include <quvi.h>

#include "tests.h"

static const gchar *URLs[] =
{
  "http://www.myspass.de/myspass/shows/tvshows/bundesvision-songcontest/Xavier-Naidoo-Der-letzte-Blick--/15026/",
  "http://www.myspass.de/myspass/shows/tvshows/stromberg/Der-Parkplatz--/867/",
  NULL
};

static const gchar *TITLEs[] =
{
  "Bundesvision Songcontest s04e01 - Xavier Naidoo - Der letzte Blick",
  "Stromberg s01e01 - Der Parkplatz",
  NULL
};

static const gchar *IDs[] =
{
  "15026",
  "867",
  NULL
};

static void test_media_myspass()
{
  struct qm_test_exact_s e;
  struct qm_test_opts_s o;
  gint i;

  for (i=0; URLs[i] != NULL; ++i)
    {
      memset(&e, 0, sizeof(e));
      memset(&o, 0, sizeof(o));

      e.title = TITLEs[i];
      e.id = IDs[i];

      o.gt0.duration_ms = TRUE;

      qm_test(__func__, URLs[i], &e, &o);
    }
}

gint main(gint argc, gchar **argv)
{
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/media/myspass", test_media_myspass);
  return (g_test_run());
}

/* vim: set ts=2 sw=2 tw=72 expandtab: */
