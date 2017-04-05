#ifndef _SYNTAX_STANDARD_H
#define _SYNTAX_STANDARD_H

#include "ccpp/ccpp.h"
#include "python/python.h"

// Syntax highlighting macros
#define HL_NORMAL 0
#define HL_NONPRINT 1
#define HL_COMMENT 2
#define HL_MLCOMMENT 3
#define HL_KEYWORD1 4
#define HL_KEYWORD2 5
#define HL_STRING 6
#define HL_NUMBER 7
#define HL_MATCH 8 //a search match

#define HL_HIGHLIGHT_STRINGS (1<<0)
#define HL_HIGHLIGHT_NUMBERS (1<<1)

struct editor_syntax {
        char **filematch;
        char **keywords;
        char singleline_comment_start[2];
        char multiline_comment_start[3];
        char multiline_comment_end[3];
        int flags;
};


typedef struct hlcolour {
        int r, g, b;
} hlcolour;

// here is an array of syntax highlights by extensions, keywords, comments, del
struct editor_syntax highlight_db[] = {
        {
                // C and C++
                CCPP_extensions,
                CCPP_keywords,
		"//", 
		"/*", 
		"*/", 
		// Python
		//Python_extensions,
		//Python_keywords,

                HL_HIGHLIGHT_STRINGS | HL_HIGHLIGHT_NUMBERS
        }
};

#define HIGHLIGHT_DB_ENTRIES (sizeof(highlight_db)/sizeof(highlight_db[0]))


#endif
