/*
 * gedit-view.h
 * This file is part of gedit
 *
 * Copyright (C) 1998, 1999 Alex Roberts, Evan Lawrence
 * Copyright (C) 2000, 2001 Chema Celorio, Paolo Maggi
 * Copyright (C) 2002-2005 Paolo Maggi
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GEDIT_VIEW_H
#define GEDIT_VIEW_H

#include <gedit/gedit-document.h>
#include <tepl/tepl.h>

G_BEGIN_DECLS

#define GEDIT_TYPE_VIEW            (gedit_view_get_type ())
#define GEDIT_VIEW(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), GEDIT_TYPE_VIEW, GeditView))
#define GEDIT_VIEW_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), GEDIT_TYPE_VIEW, GeditViewClass))
#define GEDIT_IS_VIEW(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), GEDIT_TYPE_VIEW))
#define GEDIT_IS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GEDIT_TYPE_VIEW))
#define GEDIT_VIEW_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj), GEDIT_TYPE_VIEW, GeditViewClass))

typedef struct _GeditView		GeditView;
typedef struct _GeditViewClass		GeditViewClass;
typedef struct _GeditViewPrivate	GeditViewPrivate;

struct _GeditView
{
	TeplView view;

	/*< private >*/
	GeditViewPrivate *priv;
};

struct _GeditViewClass
{
	TeplViewClass parent_class;

	void	(*drop_uris)	(GeditView  *view,
				 gchar     **uri_list);

	gpointer padding;
};

GType		gedit_view_get_type     	(void);

GtkWidget *	gedit_view_new			(GeditDocument *doc);

void		gedit_view_set_font		(GeditView   *view,
						 gboolean     default_font,
						 const gchar *font_name);

G_DEPRECATED_FOR (tepl_view_cut_clipboard)
void		gedit_view_cut_clipboard 	(GeditView *view);

G_DEPRECATED_FOR (tepl_view_copy_clipboard)
void		gedit_view_copy_clipboard 	(GeditView *view);

G_DEPRECATED_FOR (tepl_view_paste_clipboard)
void		gedit_view_paste_clipboard	(GeditView *view);

G_DEPRECATED_FOR (tepl_view_delete_selection)
void		gedit_view_delete_selection	(GeditView *view);

G_DEPRECATED_FOR (tepl_view_select_all)
void		gedit_view_select_all		(GeditView *view);

G_DEPRECATED_FOR (tepl_view_scroll_to_cursor)
void		gedit_view_scroll_to_cursor 	(GeditView *view);

G_END_DECLS

#endif /* GEDIT_VIEW_H */

/* ex:set ts=8 noet: */
