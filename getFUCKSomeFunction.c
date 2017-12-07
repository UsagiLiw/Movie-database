void getReleaseDate(char releaseDate[])
{
  char stringInput[256];
  do
  {
    printf("Please enter the release date here(YYYY-MM-DD)\n");
    printf("Enter here:");
    fget(stringInput,sizeof(stringInput),stdin);
    strcpy(releaseDate,stringInput);
  }while(checkDate(releaseDate) == 1);
}
int getSeenDate(char seenDate[])
{
  char stringInput[256];
  int status = 0;
  do
  {
    printf("Please enter the date you watched the movie(YYYY-MM-DD)\n");
    printf("Enter here(Leave blank if haven't seen yet):");
    fgets(stringInput,sizeof(stringInput),stdin);
    strcpy(seenDate,stringInput);
    if(seenDate == '\n')
    {
      printf("You haven't watch the movie\n");
      status = 1;
    }
  }while(checkSeenDate);
  return status;
}
void getMethod(char method[])
{
  char stringInput[256];
  int i;
  do
  {
    printf("Please enter your viewing method here\n");
    printf("Enter here:");
    fgets(stringInput,sizeof(stringInput),stdin);
    strcpy(method,stringInput);
    for(i = 0; i < strlen(method); i++)
    {
      method[i] = toupper(method[i]);
    }
  }while(checkMethod(method) == 1);
}
void getRaing(int* rating)
{
  char stringInput[256];
  do
  {
    printf("Please enter the rating for the movie here(1-10)\n");
    printf("Enter here:");
    fgets(stringInput; sizeof(stringInput), stdin);
    sscanf(stringInput,"%d",rating)
  }while(checkRating(rating) == 1);
}
