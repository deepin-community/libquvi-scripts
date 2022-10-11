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
  "http://www.charlierose.com/view/clip/11031",
  "http://www.charlierose.com/view/interview/11091",
  "http://www.charlierose.com/view/interview/12888",
  NULL
};

static const gchar *TITLEs[] =
{
  "Charlie Rose Greenroom with Ben Stiller",
  "Turkish Prime Minister Recep Tayyip Erdogan",
  "Walter Mossberg & Kara Swisher",
  NULL
};

static const gchar *IDs[] =
{
  "11031",
  "11091",
  "12888",
  NULL
};

static void test_media_charlierose()
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

      o.gt0.stream.video.height = TRUE;
      o.gt0.stream.video.width = TRUE;

      qm_test(__func__, URLs[i], &e, &o);
    }
}

gint main(gint argc, gchar **argv)
{
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/media/charlierose", test_media_charlierose);
  return (g_test_run());
}

/* vim: set ts=2 sw=2 tw=72 expandtab: */
