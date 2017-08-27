/*
** Copyright (c) 2008 - present, Alexis Megas.
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
** 3. The name of the author may not be used to endorse or promote products
**    derived from Dooble without specific prior written permission.
**
** DOOBLE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
** DOOBLE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef dooble_web_engine_view_h
#define dooble_web_engine_view_h

#include <QPointer>
#include <QWebEngineView>

class dooble_cookies;
class dooble_cookies_window;
class dooble_web_engine_page;

class dooble_web_engine_view: public QWebEngineView
{
  Q_OBJECT

 public:
  dooble_web_engine_view(bool is_private, QWidget *parent);
  void show_private_cookies(void);

 private:
  QPointer<dooble_cookies_window> m_cookies_window;
  bool m_is_private;
  dooble_cookies *m_cookies;
  dooble_web_engine_page *m_page;

 private slots:
  void slot_block_domain(void);
  void slot_settings_applied(void);

 protected:
  dooble_web_engine_view *createWindow(QWebEnginePage::WebWindowType type);
  void contextMenuEvent(QContextMenuEvent *event);

 signals:
  void create_tab(dooble_web_engine_view *view);
  void create_window(dooble_web_engine_view *view);
};

#endif
