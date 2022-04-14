#! /usr/bin/env python3
import base64
import zlib
import pymdownx.superfences

PORT = 8080
BIND = '192.168.1.158'
SITEURL = f'http://{BIND}:{PORT}'

AUTHOR = 'dragoncoder047'
SITENAME = 'Armdroid 1000'
SITEURL = 'https://dragoncoder047.github.io/armdroid'
LOGO = '/armdroid/armdroid.png'
LOGO_AREA_HTML = f'<a href="/armdroid"><div class="flex-row"><img src="{LOGO}" width="145" height="115" /><div id="sitename-text" class="flex-column"><h1>{SITENAME}</h1><!-- h2>SITESUBTITLE</h2 --></div></div></a>'
ICON = '/armdroid/armdroid_sm.png'
ICON_MIMETYPE = 'image/png'
THEME_CSS_FILE = '/armdroid/theme.css'
THEME_MAIN_CSS = '/static/css/main.css'
THEME_STATIC_DIR = 'static/'
USE_FOLDER_AS_CATEGORY = False

PATH = 'aaaa/'
OUTPUT_PATH = './'

TIMEZONE = 'America/New_York'

DEFAULT_LANG = 'en_US'

# maybe later...
FEED_ALL_ATOM = None
CATEGORY_FEED_ATOM = None
TRANSLATION_FEED_ATOM = None
AUTHOR_FEED_ATOM = None
AUTHOR_FEED_RSS = None

SEO_REPORT = True

DISPLAY_PAGES_ON_MENU = True
DISPLAY_CATEGORIES_ON_MENU = False
AUTHOR_SAVE_AS = AUTHORS_SAVE_AS = TAG_SAVE_AS = TAGS_SAVE_AS = CATEGORY_SAVE_AS = CATEGORIES_SAVE_AS = ARCHIVES_SAVE_AS = ''
FILENAME_METADATA = ''

# Blogroll
LINKS = (
    ('Armdroid 1000 site', 'https://armdroid1000.wordpress.com'),
    ('Dan Kohn&apos;s LabVolt 5100', 'http://www.dankohn.info/projects/armdroid.html'),
    ('Richard Morris&apos; Armdroid 1', 'https://armdroid1.blogspot.com/'),
    ('Alex Zivanovic&apos;s Armdroid 1', 'http://www.senster.com/alex_zivanovic/armdroid/index.htm'),
)

# Social
SOCIAL = (
    (f'{AUTHOR} on GitHub', f'https://github.com/{AUTHOR}'),
)

MENUITEMS = (
    ('Site root', '/'),
)

DEFAULT_PAGINATION = 10
DEFAULT_ORPHANS = 3
PAGINATION_PATTERNS = (
    (1, '{name}{extension}', '{name}{extension}'),
    (2, '{name}_{number}{extension}', '{name}_{number}{extension}'),
)

PATH_METADATA = r'(?P<path_no_ext>.*)\.[^.]*'
PAGE_URL = PAGE_SAVE_AS = 'p/{path_no_ext}.html'

PAGE_PATHS = ['']
ARTICLE_PATHS = [] # they are all pages
STATIC_PATHS = [] # everything is attached

THEME = './pelicantheme'

RELATIVE_URLS = False

READERS = {'html': None}


def kroki_fence(source, language, css_class, options, md, **kwargs):
    data = base64.urlsafe_b64encode(zlib.compress(
        source.encode('utf-8'), 9)).decode('ascii')
    lang = options.get('type', options.get('name', 'svgbob'))
    attr = ''
    if 'width' in options and 'height' in options:
        attr = f' width="{options["width"]}" height="{options["height"]}"'
    return f'<img src="https://kroki.io/{lang}/svg/{data}"{attr} />'



MARKDOWN = {
    'extension_configs': {
        'meta': {},
        'pymdownx.extra': {},
        'pymdownx.caret': {},
        'pymdownx.details': {},
        'pymdownx.highlight': {
            'use_pygments': False,  # I use Prism.js
        },
        'pymdownx.inlinehilite': {},
        "pymdownx.superfences": {
            "custom_fences": [
                {
                    'name': 'mermaid',
                    'class': 'mermaid',
                    'format': pymdownx.superfences.fence_div_format
                },  # covered by kroki, but needed for compatibility with github
                {
                    'name': 'kroki',
                    'class': 'kroki',
                    'format': kroki_fence
                }
            ]
        },
        'pymdownx.saneheaders': {},
        'pymdownx.magiclink': {},
        'pymdownx.smartsymbols': {},
        'smarty': {},
        'pymdownx.tabbed': {},
        'pymdownx.tasklist': {},
        'pymdownx.tilde': {},
        'sane_lists': {},
        'admonition': {},
        'abbr': {},
        'def_list': {},
        'toc': {},
        'footnotes': {},
        'attr_list': {},
        'markdown_figcap': {},
        'python_markdown_comments:CommentsExtension': {},
    },
    'output_format': 'html5',
}

PLUGINS = [
    # 'seo',
    'pelican.plugins.share_post',
    # 'sitemap',
    'pelican.plugins.related_posts',
    'minchin.pelican.plugins.nojekyll',
    'pelican.plugins.read_more',
    'jinja2content',
    'series',
    'pelican.plugins.more_categories'
]

if __name__ == '__main__':
    import os
    os.system(f'pelican {PATH} -o {OUTPUT_PATH} -s {__file__}')
