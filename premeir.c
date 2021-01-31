#include <stdio.h>
#include <math.h>
//global structure

typedef struct Premeir
{
    char *team_name;
    int games_played;
    int games_won;
    int games_drawn;
    int goal_diff;
    int team_points;
    //int games_lost;
} premeir;
//structure type
premeir premeir_league[20];
premeir temp_hold;
//
float median(premeir *variable_median_structure, int size, int num)
{ //median(arr_name,size);
    // puts("Started");
    if (num == 1)
    {
        //puts("Its 1111\n");
        //for games played
        int i, j;
        for (i = 0; i < size - 1; i++)
        {
            /* code here */
            for (j = i + 1; j < size; j++)
            {
                /* code here */
                if (variable_median_structure[j].games_played < variable_median_structure[j-1].games_played)
                {
                    /* code here */
                    int temp = variable_median_structure[j - 1].games_played;
                    //printf("%d\n", temp);
                    variable_median_structure[j-1].games_played = variable_median_structure[j ].games_played;
                    variable_median_structure[j].games_played = temp;
                }
            }
        }
        if (size % 2 == 0)
        {
            return (variable_median_structure[(size / 2) - 1].games_played + variable_median_structure[(size / 2)].games_played) / 2;
        }
        else
        {
            /* code here */
            return variable_median_structure[(size / 2)].games_played;
        }
    }
    else if (num == 2)
    {
        //games won
        int i, j;
        for (i = 0; i < size - 1; i++)
        {
            /* code here */
            for (j = i + 1; j < size; j++)
            {
                /* code here */
                if (variable_median_structure[j].games_won < variable_median_structure[j-1].games_won)
                {
                    /* code here */
                    int temp = variable_median_structure[j-1].games_won;
                    //printf("%d\n", temp);
                    variable_median_structure[j-1].games_won = variable_median_structure[j].games_won;
                    variable_median_structure[j].games_won = temp;
                }
            }
        }
        if (size % 2 == 0)
        {
            return (variable_median_structure[(size / 2) - 1].games_won + 
            variable_median_structure[(size / 2)].games_won) /2;
        }
        else
        {
            /* code here */
            return variable_median_structure[(size / 2)].games_won;
        }
        
    }
    else if(num==3){
                //games won
        int i, j;
        for (i = 0; i < size - 1; i++)
        {
            /* code here */
            for (j = i + 1; j < size; j++)
            {
                /* code here */
                if (variable_median_structure[j].games_drawn < variable_median_structure[j-1].games_drawn)
                {
                    /* code here */
                    int temp = variable_median_structure[j-1].games_drawn;
                    //printf("%d\n", temp);
                    variable_median_structure[j-1].games_drawn = variable_median_structure[j].games_drawn;
                    variable_median_structure[j].games_drawn = temp;
                }
            }
        }
        if (size % 2 == 0)
        {
            return (variable_median_structure[(size / 2) - 1].games_drawn + 
            variable_median_structure[(size / 2)].games_drawn) /2;
        }
        else
        {
            /* code here */
            return variable_median_structure[(size / 2)].games_drawn;
        }

    }
    else if(num ==4){
                //games won
        int i, j;
        for (i = 0; i < size - 1; i++)
        {
            /* code here */
            for (j = i + 1; j < size; j++)
            {
                /* code here */
                if (variable_median_structure[j].goal_diff < variable_median_structure[j-1].goal_diff)
                {
                    /* code here */
                    int temp = variable_median_structure[j-1].goal_diff;
                    //printf("%d\n", temp);
                    variable_median_structure[j-1].goal_diff = variable_median_structure[j].goal_diff;
                    variable_median_structure[j].goal_diff = temp;
                }
            }
        }
        if (size % 2 == 0)
        {
            return (variable_median_structure[(size / 2) - 1].goal_diff + 
            variable_median_structure[(size / 2)].goal_diff) /2;
        }
        else
        {
            /* code here */
            return variable_median_structure[(size / 2)].goal_diff;
        }

    }
    else{
                //games won
        int i, j;
        for (i = 0; i < size - 1; i++)
        {
            /* code here */
            for (j = i + 1; j < size; j++)
            {
                /* code here */
                if (variable_median_structure[j].team_points < variable_median_structure[j-1].team_points)
                {
                    /* code here */
                    int temp = variable_median_structure[j-1].team_points;
                    //printf("%d\n", temp);
                    variable_median_structure[j-1].team_points = variable_median_structure[j].team_points;
                    variable_median_structure[j].team_points = temp;
                }
            }
        }
        if (size % 2 == 0)
        {
            return (variable_median_structure[(size / 2) - 1].team_points + 
            variable_median_structure[(size / 2)].team_points) /2;
        }
        else
        {
            /* code here */
            return variable_median_structure[(size / 2)].team_points;
        }

    }
}
//sort teams
void sort(premeir *variables_premeier_structure)
{
    // for(int i=0;i<20;i++){
    //     printf("\nName:%s\n",variables_premeier_structure[i].team_name);
    // }
    //sort using points

    int i, j;
    for (i = 0; i < 19; i++)
    {
        /* code here */
        for (j = i + 1; j < 20; j++)
        {
            /* code here */
            if (variables_premeier_structure[j].team_points < variables_premeier_structure[j- 1].team_points)
            {
                /* code here */
                temp_hold = variables_premeier_structure[j-1];
                variables_premeier_structure[j-1] = variables_premeier_structure[j];
                variables_premeier_structure[j] = temp_hold;
            }
        }
    }

    printf("\n%-30s %-5s %-5s %-5s %-5s %-5s\n", "TeamName", "P", "W", "D", "GD", "Pts");

    for (int i = 19; i >= 0; i--)
    {
        printf("\n%-30s %-5d %-5d %-5d %-5d %-5d \n", variables_premeier_structure[i].team_name,
               variables_premeier_structure[i].games_played, variables_premeier_structure[i].games_won,
               variables_premeier_structure[i].games_drawn, variables_premeier_structure[i].goal_diff,
               variables_premeier_structure[i].team_points);
    }

    printf("\n\nThe Relegated teams are:\n");
    printf("\n%-30s %-5s %-5s %-5s %-5s %-5s\n", "TeamName", "P", "W", "D", "GD", "Pts");

    for (int i = 2; i >= 0; i--)
    {
        printf("\n%-30s %-5d %-5d %-5d %-5d %-5d \n", variables_premeier_structure[i].team_name,
               variables_premeier_structure[i].games_played, variables_premeier_structure[i].games_won,
               variables_premeier_structure[i].games_drawn, variables_premeier_structure[i].goal_diff,
               variables_premeier_structure[i].team_points);
    }
}

int main()
{

    //Norwich
    premeir_league[0].team_name = "Norwich City";
    premeir_league[0].games_played = 38;
    premeir_league[0].games_won = 5;
    premeir_league[0].games_drawn = 6;
    premeir_league[0].goal_diff = -49;
    premeir_league[0].team_points = 21;

    //Watford
    premeir_league[1].team_name = "Watford";
    premeir_league[1].games_played = 38;
    premeir_league[1].games_won = 8;
    premeir_league[1].games_drawn = 11;
    premeir_league[1].goal_diff = -28;
    premeir_league[1].team_points = 34;

    //Bournemouth
    premeir_league[2].team_name = "Bournemouth";
    premeir_league[2].games_played = 38;
    premeir_league[2].games_won = 9;
    premeir_league[2].games_drawn = 7;
    premeir_league[2].goal_diff = -25;
    premeir_league[2].team_points = 34;

    //AstonVilla

    premeir_league[3].team_name = "Aston Villa";
    premeir_league[3].games_played = 38;
    premeir_league[3].games_won = 9;
    premeir_league[3].games_drawn = 8;
    premeir_league[3].goal_diff = -26;
    premeir_league[3].team_points = 35;

    //West Ham
    premeir_league[4].team_name = "West Ham";
    premeir_league[4].games_played = 38;
    premeir_league[4].games_won = 10;
    premeir_league[4].games_drawn = 9;
    premeir_league[4].goal_diff = -13;
    premeir_league[4].team_points = 39;

    //Liverpool
    premeir_league[5].team_name = "Liverpool";
    premeir_league[5].games_played = 38;
    premeir_league[5].games_won = 32;
    premeir_league[5].games_drawn = 3;
    premeir_league[5].goal_diff = 52;
    premeir_league[5].team_points = 99;

    //Man City
    premeir_league[6].team_name = "Man City";
    premeir_league[6].games_played = 38;
    premeir_league[6].games_won = 26;
    premeir_league[6].games_drawn = 3;
    premeir_league[6].goal_diff = 67;
    premeir_league[6].team_points = 81;

    //Man United
    premeir_league[7].team_name = "Man United";
    premeir_league[7].games_played = 38;
    premeir_league[7].games_won = 18;
    premeir_league[7].games_drawn = 12;
    premeir_league[7].goal_diff = 30;
    premeir_league[7].team_points = 66;

    //Chelsea
    premeir_league[8].team_name = "Chelsea";
    premeir_league[8].games_played = 38;
    premeir_league[8].games_won = 20;
    premeir_league[8].games_drawn = 6;
    premeir_league[8].goal_diff = 15;
    premeir_league[8].team_points = 66;

    //Leicester City
    premeir_league[9].team_name = "Leicester City";
    premeir_league[9].games_played = 38;
    premeir_league[9].games_won = 18;
    premeir_league[9].games_drawn = 8;
    premeir_league[9].goal_diff = 26;
    premeir_league[9].team_points = 62;

    //Tottenham
    premeir_league[10].team_name = "Tottenham";
    premeir_league[10].games_played = 38;
    premeir_league[10].games_won = 16;
    premeir_league[10].games_drawn = 11;
    premeir_league[10].goal_diff = 14;
    premeir_league[10].team_points = 59;

    //Wolves
    premeir_league[11].team_name = "Wolves";
    premeir_league[11].games_played = 38;
    premeir_league[11].games_won = 15;
    premeir_league[11].games_drawn = 14;
    premeir_league[11].goal_diff = 11;
    premeir_league[11].team_points = 59;

    //Brighton
    premeir_league[12].team_name = "Brighton";
    premeir_league[12].games_played = 38;
    premeir_league[12].games_won = 9;
    premeir_league[12].games_drawn = 14;
    premeir_league[12].goal_diff = -15;
    premeir_league[12].team_points = 41;

    //Crystal Palace
    premeir_league[13].team_name = "Crystal Palace";
    premeir_league[13].games_played = 38;
    premeir_league[13].games_won = 11;
    premeir_league[13].games_drawn = 10;
    premeir_league[13].goal_diff = -19;
    premeir_league[13].team_points = 43;

    //Newcastle
    premeir_league[14].team_name = "Newcastle";
    premeir_league[14].games_played = 38;
    premeir_league[14].games_won = 11;
    premeir_league[14].games_drawn = 11;
    premeir_league[14].goal_diff = -20;
    premeir_league[14].team_points = 44;

    //Everton
    premeir_league[15].team_name = "Everton";
    premeir_league[15].games_played = 38;
    premeir_league[15].games_won = 13;
    premeir_league[15].games_drawn = 10;
    premeir_league[15].goal_diff = -12;
    premeir_league[15].team_points = 49;

    //Southampton
    premeir_league[16].team_name = "Southampton";
    premeir_league[16].games_played = 38;
    premeir_league[16].games_won = 15;
    premeir_league[16].games_drawn = 7;
    premeir_league[16].goal_diff = -9;
    premeir_league[16].team_points = 52;

    //Arsenal
    premeir_league[17].team_name = "Arsenal";
    premeir_league[17].games_played = 38;
    premeir_league[17].games_won = 14;
    premeir_league[17].games_drawn = 14;
    premeir_league[17].goal_diff = 8;
    premeir_league[17].team_points = 56;

    //Sheffield united
    premeir_league[18].team_name = "Sheffield United";
    premeir_league[18].games_played = 38;
    premeir_league[18].games_won = 14;
    premeir_league[18].games_drawn = 12;
    premeir_league[18].goal_diff = 0;
    premeir_league[18].team_points = 54;

    //Burnley
    premeir_league[19].team_name = "Burnley";
    premeir_league[19].games_played = 38;
    premeir_league[19].games_won = 15;
    premeir_league[19].games_drawn = 9;
    premeir_league[19].goal_diff = -7;
    premeir_league[19].team_points = 54;

    //calc average games drawn
    //games_played
    float games_played_average;
    int sum_games_played = 0;
    int p;
    //loop structure
    for (p = 0; p <= 19; p++)
    {
        sum_games_played += premeir_league[p].games_played;
    }
    games_played_average = sum_games_played/20.0;
    //averag games won
    float games_won_average;
    int sum_games_won = 0;
    int w;
    //loop structure
    for (w = 0; w <= 19; w++)
    {
        sum_games_won += premeir_league[w].games_won;
    }
    games_won_average = sum_games_won / 20.0;
    /*printf("Average for games won:%f\n", games_won_average);*/

    //average game_drawn

    float games_drawn_average;
    int sum_games_drawn = 0;
    int d;
    //loop structure
    for (d = 0; d <= 19; d++)
    {
        sum_games_drawn += premeir_league[d].games_drawn;
    }
    games_drawn_average = sum_games_drawn / 20.0;
    /*printf("Average for games drawn:%f\n", games_drawn_average);*/

    //average goal diff
    float goal_diff_average;
    int sum_goal_diff = 0;
    int gd;
    //loop structure
    for (gd = 0; gd <= 19; gd++)
    {
        sum_goal_diff += premeir_league[gd].goal_diff;
    }
    goal_diff_average = sum_goal_diff / 20.0;
    /*printf("Average for  goal Difference:%f\n", goal_diff_average);*/

    //points average
    //average goal diff
    float points_average;
    int sum_points = 0;
    int pa;
    //loop structure
    for (pa = 0; pa <= 19; pa++)
    {
        sum_points += premeir_league[pa].team_points;
    }
    points_average = sum_points / 20.0;
    /*printf("AverageP for the goal points:%f\n", points_average);*/

    //  sizes
    int array_size_games_played = 20;
    int array_size_games_won = 20;
    int array_size_games_drawn = 20;
    int array_size_goal_difference = 20;
    int array_size_points = 20;



    //games played
    int x, squareX, totalSquareX = 0;
    float variance, sd;

    for (int i = 0; i < 20; i++)
    {
        x = premeir_league[i].games_played;
        squareX = x * x;
        totalSquareX += squareX;
    }
    double totalAfterDivide = totalSquareX / 20.0;
    variance = ((double)totalAfterDivide) - (games_played_average * games_played_average);
    sd = sqrt(variance);
    // printf("The standard deviation for games_played is : %f\n", sd);

    //games_won

    int val;
    int m;
    int squareX_games_won;
    float variance_games_won;
    float sd__won;
    float total_square_won = 0.0;

    for (m = 0; m <= 20; m++)
    {
        val = premeir_league[m].games_won;
        squareX_games_won = val * val;
        //printf("%d : %d\n",val, squareX_games_won);
        total_square_won += squareX_games_won;
    }
    double divide_games_won = total_square_won / 20.0;
    variance_games_won = divide_games_won - (games_won_average * games_won_average);
    sd__won = sqrt(variance_games_won);
    // printf("The standard deviation for games_won is : %f\n", sd__won);

    //games_drawn
    int D, squareX_games_drawn, totalSquareX_games_drawn = 0;
    float variance_games_drawn, sd_games_drawn;
    for (int _m = 0; _m < 20; _m++)
    {
        D = premeir_league[_m].games_drawn;
        squareX_games_drawn = D * D;
        totalSquareX_games_drawn += squareX_games_drawn;
    }
    double divide_games_drawn = totalSquareX_games_drawn / 20.0;
    variance_games_drawn = divide_games_drawn - (games_drawn_average * games_drawn_average);
    sd_games_drawn = sqrt(variance_games_drawn);
    // printf("\nThe standard deviation for games_drawn is : %f\n", sd_games_drawn);

    //goal_diff;
    int K, square_goal_diff, totalsquare_goal_diff = 0;
    float variance_goal_diff, sd_goal_diff;
    for (int k = 0; k < 20; k++)
    {
        K = premeir_league[k].goal_diff;
        square_goal_diff = K * K;
        totalsquare_goal_diff += square_goal_diff;
    }
    double divide_goal_diff_total_square = totalsquare_goal_diff / 20.0;
    variance_goal_diff = divide_goal_diff_total_square - (goal_diff_average * goal_diff_average);
    sd_goal_diff = sqrt(variance_goal_diff);
    // printf("\nThe standard deviation for goal_diff is : %f\n", sd_goal_diff);

    //points

    int P, square_team_points, totalsquare_team_points = 0;
    float variance_team_points, sd_team_points;
    for (int p = 0; p < 20; p++)
    {
        P = premeir_league[p].team_points;
        square_team_points = P * P;
        totalsquare_team_points += square_team_points;
    }
    double divide_team_points_total_square = totalsquare_team_points / 20.0;
    variance_team_points = divide_team_points_total_square - (points_average * points_average);
    sd_team_points = sqrt(variance_team_points);
    // printf("\nThe standard deviation for team_points is : %f\n", sd_team_points);

    //coefficient of varitaion

    //games_played
    float coff_games_played = (sd / games_played_average) * 100;

    // printf("coefficient of variation for games played is :%.1f\n", coff_games_played);
    //games_won
    float coff_games_won = (sd__won / games_won_average) * 100;
    // printf("coefficient of variation for games won is :%.1f\n", coff_games_won);
    //games_drawn
    float coff_games_drawn = (sd_games_drawn / games_drawn_average) * 100;
    // printf("coefficient of variation for games drawn is :%.1f\n", coff_games_drawn);

    //goal_diff
    float coff_games_diff = (sd_goal_diff / goal_diff_average) * 100;
    //printf("Doff:%f, Average:%f", sd_goal_diff, goal_diff_average);
    // printf("coefficient of variation for goal diff is :%.1f\n", coff_games_diff);

    //points

    float coff_points = (sd_team_points / points_average) * 100;
    // printf("coefficient of variation for team points is %.1f", coff_points);

    /*sorting teams by points
     sort(premeir_league);*/
    int choice;
    printf("\n\t\t====CHOICES=======\n");
    printf("\n1:DISPLAY AVERAGES");
    printf("\n2:DISPLAY MEDIAN");
    printf("\n3:DISPLAY STANDARD DEVIATION");
    printf("\n4:DISPLAY COEFFICIENT OF VARIATION");
    printf("\n5:DISPLAY SORTED LIST AND RELAGATED TEAMS\n");

    printf("\nEnter Choice:");

    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        puts("\n=========AVerages================================\n");
        printf("Average for the goal points:%f\n", points_average);
        printf("Average for games played: %f\n", games_played_average);
        printf("Average for games drawn:%f\n", games_drawn_average);
        printf("Average for  goal Difference:%f\n", goal_diff_average);
        printf("Average for games won:%f\n", games_won_average);

        break;
    case 2:
    puts("\t=============================Median===================================");
    printf("The median for games played: %lf\n", median(premeir_league, array_size_games_played, 1));
    printf("The median for games won: %lf\n", median(premeir_league, array_size_games_won, 2));
    printf("The median for drawn: %lf\n", median(premeir_league, array_size_games_drawn, 3));
    printf("The median for goal difference: %lf\n", median(premeir_league, array_size_goal_difference, 4));
    printf("The median for points: %lf\n", median(premeir_league, array_size_points, 5));

        break;
    case 3:
        printf("\t============The standard Deviation==============\n");
        printf("The standard deviation for games_played is : %f\n", sd);
        printf("The standard deviation for games_won is : %f\n", sd__won);
        printf("\nThe standard deviation for games_drawn is : %f\n", sd_games_drawn);
        printf("\nThe standard deviation for goal_diff is : %f\n", sd_goal_diff);
        printf("\nThe standard deviation for team_points is : %f\n", sd_team_points);
        break;
    case 4:
        printf("\n\t============Cofficient OF Varition==============\n");
        
        printf("coefficient of variation for games played is :%.1f\n", coff_games_played);
        printf("coefficient of variation for games won is :%.1f\n", coff_games_won);
        printf("coefficient of variation for games drawn is :%.1f\n", coff_games_drawn);
        printf("coefficient of variation for goal diff is :%.1f\n", coff_games_diff);
        printf("coefficient of variation for team points is %.1f", coff_points);
        break;


    case 5:
        sort(premeir_league);
        break;
    default:
        break;
    }
}
