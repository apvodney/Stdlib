/*
 *  Implementation of external standard class CommandLine.
 */


#include <string.h>

#include "sac.h"


/*****************************************************/


typedef struct COMLINE
{
  int argc;
  char **argv;
}
ComLine;


/*****************************************************/


extern ComLine *SACo_CommandLine__TheCommandLine;


/*****************************************************/


ComLine *create_TheCommandLine( void)
{
  ComLine *parameters;
  
  parameters=(ComLine *)SAC_MALLOC(sizeof(ComLine));
  
  SAC_COMMANDLINE_GET( parameters->argc, parameters->argv);
  
  return(parameters);
}


/*****************************************************/


int SACargc( void)
{
  return(SACo_CommandLine__TheCommandLine->argc);
}


/*****************************************************/


char *SACargv(int n)
{
  char *result;
  
  if (n<SACo_CommandLine__TheCommandLine->argc)
  {
    result=(char*)SAC_MALLOC(strlen((SACo_CommandLine__TheCommandLine->argv)[n])+1);
  
    strcpy(result, (SACo_CommandLine__TheCommandLine->argv)[n]);
  }
  else
  {
    result=(char*)SAC_MALLOC(1);
    result[0]=0;
  }
  
  return(result);
}


/*****************************************************/


char *SACargvall( void)
{
  char *result;
  int len,i;
  
  len=0;
  
  for (i=0; i<SACo_CommandLine__TheCommandLine->argc; i++)
  {
    len += strlen(SACo_CommandLine__TheCommandLine->argv[i]);
  }
  
  result=(char*)SAC_MALLOC(len+1+SACo_CommandLine__TheCommandLine->argc);

  strcpy(result, (SACo_CommandLine__TheCommandLine->argv)[0]);
  
  for (i=1; i<SACo_CommandLine__TheCommandLine->argc; i++)
  {
    strcat(result, " ");
    strcat(result, (SACo_CommandLine__TheCommandLine->argv)[i]);
  }
  
  return(result);
}


/*****************************************************/





