/*
Navn: Alexander Skytt Steffensen
E-mail: asteff20@student.aau.dk
Gruppe: A408b
Studieretning: Software
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEAM_NAME_LEN 4
#define WEEKDAY_LEN 4
#define DATE_LEN 2
#define TIME_LEN 2
#define TYPE_OF_GOALS 2
#define NUM_OF_MATCHES 182
#define NUM_OF_TEAMS 14
#define MAX_AMT_OF_DATA 100

struct team {
  char team_name[TEAM_NAME_LEN];
  int point;
  int goals[TYPE_OF_GOALS];
};

struct match {
  char weekday[WEEKDAY_LEN];
  int date[DATE_LEN];
  int time[TIME_LEN];
  char home_team[TEAM_NAME_LEN];
  char away_team[TEAM_NAME_LEN];
  int result[2];
  int spectators;
};

typedef struct team team;
typedef struct match match;

void calc_scoreboard(void);
void read_file(match *matches, FILE *data);
void give_team_names(team *teams);
void calc_scores(match* matches, team *teams);
void calc_winner(char match_winner[], match match);
int h(char *team_name);
int score_comp(const void *a, const void *b);
void print_scoreboard(team *teams);


/* main kører calc_scoreboard */
int main(void) {
  calc_scoreboard();
  return EXIT_SUCCESS;
}

/* calc_scoreboard laver kamp og hold arrays og kalder de andre 
   funktioner til at lave scoreboardet ved 26. runde og printe det.*/
void calc_scoreboard(void){
  match matches[NUM_OF_MATCHES];
  team teams[NUM_OF_TEAMS];
  FILE* match_data = fopen("kampe-2019-2020.txt", "r");

  read_file(matches, match_data);
  fclose(match_data);
  give_team_names(teams);
   
  calc_scores(matches, teams);
  
  qsort(teams, NUM_OF_TEAMS, sizeof(team), score_comp);
  print_scoreboard(teams);
}

/* read_file læser filen over fodboldkampene og 
ligger dataen ind i et array af structs*/
void read_file(match *matches, FILE *data) {
  char line[MAX_AMT_OF_DATA];
  int i;

  for (i = 0; i < NUM_OF_MATCHES; i++) {
    fgets(line, MAX_AMT_OF_DATA, data);
    sscanf(line, " %s  %d/%d   %d.%d   %s - %s   %d - %d   %d",
           matches[i].weekday, &matches[i].date[0], &matches[i].date[1],
           &matches[i].time[0], &matches[i].time[1],  matches[i].home_team, 
           matches[i].away_team, &matches[i].result[0], &matches[i].result[1],
           &matches[i].spectators
          );
  }
}

/* give_team_names fordeler navnene i arrayet af team structs */
void give_team_names(team *teams) {
  char *team_names[NUM_OF_TEAMS] = {"FCM", "EFB", "SDR", "RFC", "ACH", "LBK", "AaB", 
                                    "FCN", "OB", "FCK", "BIF", "SIF", "HOB", "AGF"};
  int i;
  for (i = 0; i < NUM_OF_TEAMS; i++) {
    strcpy(teams[i].team_name, team_names[i]);
    teams[i].point = 0;
    teams[i].goals[0] = 0;
    teams[i].goals[1] = 0;
  }
}

/* calc_scores beregner de forskellige holds point, mål scoret og mål imod hold*/
void calc_scores(match *matches, team *teams) {
  int i;
  char *match_winner = (char*) malloc(TEAM_NAME_LEN * sizeof(char));
  
  for (i = 0; i < NUM_OF_MATCHES; i++) {
    teams[h(matches[i].home_team)].goals[0] += matches[i].result[0];
    teams[h(matches[i].home_team)].goals[1] += matches[i].result[1];
    teams[h(matches[i].away_team)].goals[0] += matches[i].result[1]; 
    teams[h(matches[i].away_team)].goals[1] += matches[i].result[0];
  
    calc_winner(match_winner, matches[i]);

    if (strcmp(match_winner, "TIE") == 0){
      teams[h(matches[i].home_team)].point += 1;
      teams[h(matches[i].away_team)].point += 1;
    }
    else
      teams[h(match_winner)].point += 3;
  }
  free(match_winner);
}

/* calc_winner finder vinderen af kampen som kommer gennem input parameter. */
void calc_winner(char *match_winner, match match) {
  if (match.result[0] > match.result[1])
    strcpy(match_winner, match.home_team);
  else if (match.result[0] < match.result[1])
    strcpy(match_winner, match.away_team);
  else
    strcpy(match_winner, "TIE");
}

/* h er en hash funktion som finder positionen i hold arrayet hvor 
   holdnavnet der kommer som input parameter finder sted. */
int h(char *team_name) {
  char *team_names[NUM_OF_TEAMS] = {"FCM", "EFB", "SDR", "RFC", "ACH", "LBK", "AaB", 
                                    "FCN", "OB", "FCK", "BIF", "SIF", "HOB", "AGF"};
  int i;

  for (i = 0; i < NUM_OF_TEAMS; i++) {
    if (strcmp(team_name, team_names[i]) == 0)
      return i;
  }
  return -1;
}

/* score_comp er min compare funktion jeg bruger til qsort i calc_scoreboard. 
   Den sorterer først efter point og derefter efter mål differencen */
int score_comp(const void *a, const void *b){
  int point1 = ((team*)a)->point, point2 = ((team*)b)->point;
  int goals_from1 = ((team*)a)->goals[0], goals_from2 = ((team*)b)->goals[0];
  int goals_against1 = ((team*)a)->goals[1], goals_against2 = ((team*)b)->goals[1];

  if (point1 == point2)
    return (goals_from2 - goals_against2) - (goals_from1 - goals_against1);
  else
    return point2 - point1;
}

/* print_scoreboard printer det sorterede scoreboard efter 26 runder */
void print_scoreboard(team *teams) {
  int i;
  printf("\n----------------------------\n");
  printf("| TEAMNAME | PTS | GF | GA |\n");
  printf("----------------------------\n");
  for (i = 0; i < NUM_OF_TEAMS; i++){
    printf("|%-9s |  %.2d | %.2d | %.2d |     \n",
           teams[i].team_name, teams[i].point, 
           teams[i].goals[0], teams[i].goals[1]
          );
    printf("----------------------------\n");
  }
}