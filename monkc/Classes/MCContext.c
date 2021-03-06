#include "MCContext.h"
#include "MCString.h"

oninit(MCContext)
{
    if (init(MCObject)) {
        obj->selectionChar=0;
        return obj;
    }else{
        return null;
    }
}

fun(MCContext, MCContext*, newWithArgs, int argc, char** argv)
{
	MCContext* res = new(MCContext);
	res->argc = argc;
	res->argv = argv;
	return res;
}

struct privateData
{
	/* data */
};

static char get_one_char()
{
    char cf = '\0';
    while(!MCString_isNewLine(&cf)) {
        cf = getchar();
    };//clear the buff
	return cf;
}

static void get_chars_until_enter(char resultString[])
{
	char tc = NUL;
	int i=0;
	while(!MCString_isNewLine(&tc)){
        tc = getchar();
		resultString[i]=tc;
		i++;
		putchar(tc);
	}
	resultString[i] = NUL;
	putchar(tc);
}

fun(MCContext, void, bye, voida)
{	
	runtime_log("%s\n", "MCContext goodbye");
    superbye(MCObject);
}

fun(MCContext, void, dumpParas, voida)
{
	int i;
	for (i = 0; i < obj->argc; ++i)
	{
		runtime_log("%s\n", obj->argv[i]);
	}
}

fun(MCContext, char*, getPara, int index)
{
	return obj->argv[index];
}

fun(MCContext, int, isIndexedParaEqualTo, int index, char* para)
{
	char* para1 = obj->argv[index];
	if (para1==null)return 0;
	if (strcmp(para1, para)==0)return 1;
	else return 0;
}

fun(MCContext, int, isHavePara, char* para)
{
	if(obj==null)return 0;
	int i, res;
	for (i = 0; i < obj->argc; ++i)
	{
		char* tmp = obj->argv[i];
        if(tmp!=null && para!=null)res = strcmp(tmp, para);
		else return 0;

		if(res==0)return 1;
	}
	return 1;
}

fun(MCContext, char, showMenuAndGetSelectionChar, int count, ...)
{
	va_list ap;
	va_start(ap, count);
	int i;
	for (i = 0; i < count; ++i)
	{
		char* arg = va_arg(ap, char*);
		printf("%d.%s\n", i+1, arg);
	}
	printf("%s\n", "your selection is?");
	va_end(ap);
	obj->selectionChar = get_one_char();
	return obj->selectionChar;
}

fun(MCContext, int, showConfirmAndGetBOOL, const char* confirm)
{
	printf("%s (y/n)?\n", confirm);
	char cf = get_one_char();
	if (cf=='y'){
		return 1;
	}
	return 0;
}

fun(MCContext, void, getUserInputString, char resultString[])
{
	get_chars_until_enter(resultString);
}

/*
#include <stdlib.h>
char *getenv(const char *name);
int putenv(char *str); //need "key=value"
int setenv(const char *name, const char *value, int rewrite);
int unsetenv(const char *name);
*/

fun(MCContext, char*, getEnvironmentVar, const char* key)
{
	//char *getenv(const char *name);
	return getenv(key);
}

fun(MCContext, int, setEnvironmentVar, const char* key, const char* value, int isOverwrite)
{
	//int setenv(const char *name, const char *value, int rewrite);
	if (setenv(key, value, isOverwrite)==0)
		return 0;
	else
		return -1;
}

fun(MCContext, int, clearEnvironmentVar, const char* key)
{
	//int unsetenv(const char *name);
	if (unsetenv(key)==0)
		return 0;
	else
		return -1;
}

onload(MCContext)
{
    if (load(MCObject)) {
        bid(MCContext, MCContext*, newWithArgs, int argc, char** argv);
        bid(MCContext, void, bye);
        bid(MCContext, void, dumpParas);
        bid(MCContext, char*, getPara, int index);
        bid(MCContext, int, isIndexedParaEqualTo, int index, char* para);
        bid(MCContext, int, isHavePara, char* para);
        bid(MCContext, char, showMenuAndGetSelectionChar, int count, ...);
        bid(MCContext, int, showConfirmAndGetBOOL, const char* confirm);
        bid(MCContext, void, getUserInputString, char resultString[]);
        bid(MCContext, char*, getEnvironmentVar, const char* key);
        bid(MCContext, int, setEnvironmentVar, const char* key, const char* value, int isOverwrite);
        bid(MCContext, int, clearEnvironmentVar, const char* key);
        return cla;
    }else{
        return null;
    }
}
