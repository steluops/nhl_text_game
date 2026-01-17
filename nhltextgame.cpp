// libraries
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    // variables
    const int SIZE = 32, SPACE = 2;
    string teamNames[SIZE] = {}, division[SIZE] = {};
    string locationDecider[SPACE] = {"vs.", "at"};
    string faceoffWinOrLose[SPACE] = {"win", "lose"};
    string passingChance[SPACE] = {"success", "failed"};
    string shootingChance[SPACE] = {"success", "failed"};
    string recoveryChance[SPACE] = {"success", "failed"};
    string cpuPassOrShoot[SPACE] = {"pass", "shoot"};
    string cpuPassingChance[SPACE] = {"success", "failed"};
    string cpuShootingChance[SPACE] = {"success", "failed"};
    string puckPossession = "";
    string headers = "", record = "";
    string yourTeam = "", opponentTeam = "", awayOrHome = "", faceoff = "";
    string passing = "", shooting = "", recovering = "";
    string awayTeam = "", homeTeam = "", yesOrNo = "";
    string returnHome = "";
    string newAwayScore = "", newHomeScore = "", newOpponentScore = "";
    string newPeriodNumber = "", newTimeLimit = "", newYourScore = "";
    string user = "", opponent = "", cpu = "";
    bool goal = false;
    int yourScore = 0, opponentScore = 0;
    int count = 0, selectedTeam = 0;
    int periodNumber = 1, awayScore = 0, homeScore = 0;
    int i = 0;
    int timeLimit = 20;
    bool teamChosen = false, gameOver = false, startGame = false;
    bool periodOver = false;
    char passOrShoot = ' ';
    
    // acquire and open the file
    ifstream nhlFile;
    nhlFile.open("nhl.csv");

    // getting the headers in the .csv file
    getline(nhlFile, headers);

    while(getline(nhlFile, record))
    {

        int comma = record.find(',');
        teamNames[count] = record.substr(0, comma);
        record = record.substr(comma + 1, record.length());

        division[count] = (record);

        // stopping if file
        if(count == SIZE)
        {
            break;
        }

        count++;
    }
    // closing the .csv file
    nhlFile.close();

    cout << "Welcome! Please select a team!\n";
    // display the teams to choose from
    while(teamChosen == false)
    {

        cout << "1. " << teamNames[0] << ", " << "(" << division[0] << ")" << endl
             << "2. " << teamNames[1] << ", " << "(" << division[1] << ")" << endl
             << "3. " << teamNames[2] << ", " << "(" << division[2] << ")" << endl
             << "4. " << teamNames[3] << ", " << "(" << division[3] << ")" << endl
             << "5. " << teamNames[4] << ", " << "(" << division[4] << ")" << endl
             << "6. " << teamNames[5] << ", " << "(" << division[5] << ")" << endl
             << "7. " << teamNames[6] << ", " << "(" << division[6] << ")" << endl
             << "8. " << teamNames[7] << ", " << "(" << division[7] << ")" << endl
             << "9. " << teamNames[8] << ", " << "(" << division[8] << ")" << endl
             << "10. " << teamNames[9] << ", " << "(" << division[9] << ")" << endl
             << "11. " << teamNames[10] << ", " << "(" << division[10] << ")" << endl
             << "12. " << teamNames[11] << ", " << "(" << division[11] << ")" << endl
             << "13. " << teamNames[12] << ", " << "(" << division[12] << ")" << endl
             << "14. " << teamNames[13] << ", " << "(" << division[13]<< ")" << endl
             << "15. " << teamNames[14] << ", " << "(" << division[14] << ")" << endl
             << "16. " << teamNames[15] << ", " << "(" << division[15] << ")" << endl
             << "17. " << teamNames[16] << ", " << "(" << division[16] << ")" << endl
             << "18. " << teamNames[17] << ", " << "(" << division[17] << ")" << endl
             << "19. " << teamNames[18] << ", " << "(" << division[18] << ")" << endl
             << "20. " << teamNames[19] << ", " << "(" << division[19] << ")" << endl
             << "21. " << teamNames[20] << ", " << "(" << division[20] << ")" << endl
             << "22. " << teamNames[21] << ", " << "(" << division[21] << ")" << endl
             << "23. " << teamNames[22] << ", " << "(" << division[22] << ")" << endl
             << "24. " << teamNames[23] << ", " << "(" << division[23] << ")" << endl
             << "25. " << teamNames[24] << ", " << "(" << division[24] << ")" << endl
             << "26. " << teamNames[25] << ", " << "(" << division[25] << ")" << endl
             << "27. " << teamNames[26] << ", " << "(" << division[26] << ")" << endl
             << "28. " << teamNames[27] << ", " << "(" << division[27] << ")" << endl
             << "29. " << teamNames[28] << ", " << "(" << division[28] << ")" << endl
             << "30. " << teamNames[29] << ", " << "(" << division[29] << ")" << endl
             << "31. " << teamNames[30] << ", " << "(" << division[30] << ")" << endl
             << "32. " << teamNames[31] << ", " << "(" << division[31] << ")" << endl;
        
        cout <<"Team: ";
        cin >> selectedTeam;
        
        if(cin.fail() || selectedTeam < 1 || selectedTeam > 32)
        {
            cout << "Error! Please try again!\n";
            cin.clear();
            cin.ignore(256,'\n');
        }
        teamChosen = true;
        break;
    }
    
    // displaying the key players of selected team
    switch(selectedTeam)
    {
    case 1:
    {
        cout << teamNames[0] << endl;
        cout << "Key Players:\n";
        cout << "Troy Terry" << endl
             << "Cutter Gauthier" << endl
             << "Leo Carlsson" << endl;
    }
    break;
    case 2:
    {
        cout << teamNames[1] << endl;
        cout << "Key Players:\n";
        cout << "David Pastrnak" << endl
             << "Pavel Zacha" << endl
             << "Morgan Geekie" << endl;
    }
    break;
    case 3:
    {
        cout << teamNames[2] << endl;
        cout << "Key Players:\n";
        cout << "Tage Thompson" << endl
             << "Rasmus Dahlin" << endl
             << "Alex Tuch" << endl;
    }
    break;
    case 4:
    {
        cout << teamNames[3] << endl;
        cout << "Key Players:\n";
        cout << "Nazem Kadri" << endl
             << "Rasmus Andersson" << endl
             << "Mikael Backlund" << endl;
    }
    break;
    case 5:
    {
        cout << teamNames[4] << endl;
        cout << "Key Players:\n";
        cout << "Sebastian Aho" << endl
             << "Andrei Svechnikov" << endl
             << "Nikolaj Ehlers" << endl;
    }
    break;
    case 6:
    {
        cout << teamNames[5] << endl;
        cout << "Key Players:\n";
        cout << "Connor Bedard" << endl
             << "Tyler Bertuzzi" << endl
             << "Andre Burakovsky" << endl;
    }
    break;
    case 7:
    {
        cout << teamNames[6] << endl;
        cout << "Key Players:\n";
        cout << "Nathan MacKinnon" << endl
             << "Martin Necas" << endl
             << "Cale Makar" << endl;
    }
    break;
    case 8:
    {
        cout << teamNames[7] << endl;
        cout << "Key Players:\n";
        cout << "Zack Werenski" << endl
             << "Adam Fantilli" << endl
             << "Boone Jenner" << endl;
    }
    break;
    case 9:
    {
        cout << teamNames[8] << endl;
        cout << "Key Players:\n";
        cout << "Mikko Rantanen" << endl
             << "Jason Robertson" << endl
             << "Wyatt Johnston" << endl;
    }
    break;
    case 10:
    {
        cout << teamNames[9] << endl;
        cout << "Key Players:\n";
        cout << "Dylan Larkin" << endl
             << "Lucas Raymond" << endl
             << "Patrick Kane" << endl;
    }
    break;
    case 11:
    {
        cout << teamNames[10] << endl;
        cout << "Key Players:\n";
        cout << "Connor McDavid" << endl
             << "Leon Draisaitl" << endl
             << "Evan Bouchard" << endl;
    }
    break;
    case 12:
    {
        cout << teamNames[11] << endl;
        cout << "Key Players:\n";
        cout << "Brad Marchand" << endl
             << "Matthew Tkachuk" << endl
             << "Sam Bennett" << endl;
    }
    break;
    case 13:
    {
        cout << teamNames[12] << endl;
        cout << "Key Players:\n";
        cout << "Adrian Kempe" << endl
             << "Kevin Fiala" << endl
             << "Quinton Byfield" << endl;
    }
    break;
    case 14:
    {
        cout << teamNames[13] << endl;
        cout << "Key Players:\n";
        cout << "Kirill Kaprizov" << endl
             << "Brock Faber" << endl
             << "Matt Boldy" << endl;
    }
    break;
    case 15:
    {
        cout << teamNames[14] << endl;
        cout << "Key Players:\n";
        cout << "Nick Suzuki" << endl
             << "Cole Caufield" << endl
             << "Lane Hutson" << endl;
    }
    break;
    case 16:
    {
        cout << teamNames[15] << endl;
        cout << "Key Players:\n";
        cout << "Ryan O'Reilly" << endl
             << "Filip Forsberg" << endl
             << "Luke Evangelista" << endl;
    }
    break;
    case 17:
    {
        cout << teamNames[16] << endl;
        cout << "Key Players:\n";
        cout << "Jesper Bratt" << endl
             << "Nico Hischier" << endl
             << "Dawson Mercer" << endl;
    }
    break;
    case 18:
    {
        cout << teamNames[17] << endl;
        cout << "Key Players:\n";
        cout << "Matthew Barzal" << endl
             << "Bo Horvat" << endl
             << "Matthew Schaefer" << endl;
    }
    break;
    case 19:
    {
        cout << teamNames[18] << endl;
        cout << "Key Players:\n";
        cout << "Artemi Panarin" << endl
             << "Mika Zibanejad" << endl
             << "Adam Fox" << endl;
    }
    break;
    case 20:
    {
        cout << teamNames[19] << endl;
        cout << "Key Players:\n";
        cout << "Tim Stutzle" << endl
             << "Drake Batherson" << endl
             << "Dylan Cozens" << endl;
    }
    break;
    case 21:
    {
        cout << teamNames[20] << endl;
        cout << "Key Players:\n";
        cout << "Trevor Zegras" << endl
             << "Travis Konecny" << endl
             << "Christian Dvorak" << endl;
    }
    break;
    case 22:
    {
        cout << teamNames[21] << endl;
        cout << "Key Players:\n";
        cout << "Sidney Crosby" << endl
             << "Bryan Rust" << endl
             << "Erik Karlsson" << endl;
    }
    break;
    case 23:
    {
        cout << teamNames[22] << endl;
        cout << "Key Players:\n";
        cout << "Macklin Celebrini" << endl
             << "Alex Wennberg" << endl
             << "Will Smith" << endl;
    }
    break;
    case 24:
    {
        cout << teamNames[23] << endl;
        cout << "Key Players:\n";
        cout << "Jordan Eberle" << endl
             << "Chandler Stephenson" << endl
             << "Matty Beniers" << endl;
    }
    break;
    case 25:
    {
        cout << teamNames[24] << endl;
        cout << "Key Players:\n";
        cout << "Robert Thomas" << endl
             << "Pavel Buchnevich" << endl
             << "Justin Faulk" << endl;
    }
    break;
    case 26:
    {
        cout << teamNames[25] << endl;
        cout << "Key Players:\n";
        cout << "Nikita Kucherov" << endl
             << "Jake Guentzel" << endl
             << "Brandon Hagel" << endl;
    }
    break;
    case 27:
    {
        cout << teamNames[26] << endl;
        cout << "Key Players:\n";
        cout << "William Nylander" << endl
             << "Auston Matthews" << endl
             << "Matthew Knies" << endl;
    }
    break;
     case 28:
    {
        cout << teamNames[27] << endl;
        cout << "Key Players:\n";
        cout << "Clayton Keller" << endl
             << "Dylan Guenther" << endl
             << "Nick Schmaltz" << endl;
    }
    break;
     case 29:
    {
        cout << teamNames[28] << endl;
        cout << "Key Players:\n";
        cout << "Elias Pettersson" << endl
             << "Kiefer Sherwood" << endl
             << "Thatcher Demko" << endl;
    }
    break;
     case 30:
    {
        cout << teamNames[29] << endl;
        cout << "Key Players:\n";
        cout << "Jack Eichel" << endl
             << "Mark Stone" << endl
             << "Mitch Marner" << endl;
    }
    break;
     case 31:
    {
        cout << teamNames[30] << endl;
        cout << "Key Players:\n";
        cout << "Alexander Ovechkin" << endl
             << "Tom Wilson" << endl
             << "Dylan Strome" << endl;
    }
    break;
    case 32:
    {
        cout << teamNames[31] << endl;
        cout << "Key Players:\n";
        cout << "Mark Scheifele" << endl
             << "Kyle Connor" << endl
             << "Gabriel Villardi" << endl;
    }
    break;
    default:
    {
        cout << "Please try again." << endl;
    }
    }

    // validating your team
    yourTeam = teamNames[selectedTeam - 1];
    user = yourTeam;
    opponent = opponentTeam;

    // finding out away or home match
    srand(time(NULL));
    awayOrHome = locationDecider[rand() % 2];

    // finding an opponent
    srand(time(NULL));
    opponentTeam = teamNames[rand() % 32];
    cout << "\nYour opponent is the " << opponentTeam << "." << endl;
    cout << yourTeam << " " << awayOrHome << " " << opponentTeam << endl;

    if(awayOrHome == "vs.")
    {
        homeTeam = yourTeam;
        homeScore = yourScore;
        awayTeam = opponentTeam;
        awayScore = opponentScore;

    }
    else if(awayOrHome == "at")
    {
        awayTeam = yourTeam;
        awayScore = yourScore;
        homeTeam = opponentTeam;
        homeScore = opponentScore;
    }

    // validating if the user is ready to play
    do
    {
        cout << "Are you ready to play? (y/n): ";
        cin >> yesOrNo;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(256,'\n');
        }
        else if(yesOrNo == "y" || yesOrNo == "Y")
        {
            startGame = true;
            break;
        }
        else if(yesOrNo == "n" || yesOrNo == "N")
        {
            cout << "Do you want to return to the main menu?: ";
            cin >> returnHome;

            if(cin.fail())
            {
                cin.clear();
                cin.ignore(256,'\n');
            }
            else if(returnHome == "y" || returnHome == "Y")
            {
                return 0;
            }
            else if(returnHome == "n" || returnHome == "N")
            {
                continue;
            }
        }
    }while(startGame == false);

    // the game loop 
    do
    {   
        // display the scoreboard
        cout << endl;
        cout << setw(10) << "Period: " << periodNumber << setw(15) << "Time: " << timeLimit
             << " minutes" << endl;
        cout << awayTeam << ": " << awayScore << endl;
        cout << homeTeam << ": " << homeScore << endl;

        if(timeLimit == 20 || goal == true || periodOver == true)
        {
            // determining faceoff outcome
            srand(time(NULL));
            faceoff = faceoffWinOrLose[rand() % 2];

            if(faceoff == "win")
            {
                puckPossession = yourTeam;
                cout << endl;
                cout << yourTeam << " have won the faceoff!" << endl;
            }
            else if(faceoff == "lose")
            {
                puckPossession = opponentTeam;
                cout << endl;
                cout << opponentTeam << " have won the faceoff!" << endl;
            }
        }
        
        // if your team won the faceoff
        if(puckPossession == yourTeam)
        {
            // asking user if they want to pass or shoot the puck
            cout << "(P)ass or (S)hoot the puck?" << endl;
            cin >> passOrShoot;

            switch(passOrShoot)
            {
            case 'p':
            case 'P':
            {
                // passing outcome
                srand(time(NULL));
                passing = passingChance[rand() % 2];

                if(passing == "success")
                {
                    cout << "You've successfully passed the puck!" << endl;
                    timeLimit = timeLimit - 1;
                    puckPossession = yourTeam;
                }
                else if(passing == "failed")
                {
                    cout << "The pass was picked off by the other team." << endl;
                    timeLimit = timeLimit - 1;
                    puckPossession = opponentTeam;
                }
            }
            break;
            case 's':
            case 'S':
            {
                // shooting outcome
                srand(time(NULL));
                shooting = shootingChance[rand() % 2];

                if(shooting == "success")
                {
                    // adding a goal to the scoreboard
                    cout << yourTeam << " GOAL!" << endl;
                    yourScore = yourScore + 1;

                    if(yourTeam == awayTeam)
                    {
                        awayScore = awayScore + 1;
                    }
                    else if(yourTeam == homeTeam)
                    {
                        homeScore = homeScore + 1;
                    }

                    goal = true;
                }
                else if(shooting == "failed")
                {
                    cout << "Your team failed to score." << endl;

                    // recovering the puck chance
                    srand(time(NULL));
                    recovering = recoveryChance[rand() % 2];

                    if(recovering == "success")
                    {
                        cout << "Your team succesfully recovered the puck." << endl;
                        timeLimit = timeLimit - 1;
                    }    
                    else
                    {
                        cout << "Your team failed to recover the puck." << endl;
                        timeLimit = timeLimit - 1;
                        puckPossession = opponentTeam;
                    }

                }
            }
            break;
            default:
            {
                cout << "Error!\n";
                timeLimit = timeLimit;
            }
            }

        }
        // the opponent/cpu has the puck
        else if(puckPossession == opponentTeam)
        {
            srand(time(NULL));
            cpu = cpuPassOrShoot[rand() % 2];

            if(cpu == "pass")
            {
                // the chances of cpu completing a pass
                srand(time(NULL));
                passing = cpuPassingChance[rand() % 2];

                if(passing == "success")
                {
                    cout << "Opponent team successfully passed the puck." << endl;
                    timeLimit = timeLimit - 1;
                    puckPossession = opponentTeam;
                }
                else if(passing == "failed")
                {
                    cout << "The pass was picked off by your team!" << endl;
                    timeLimit = timeLimit - 1;
                    puckPossession = yourTeam;
                }
            }
            else if(cpu == "shoot")
            {
                // the chances the cpu scores a goal
                srand(time(NULL));
                shooting = cpuShootingChance[rand() % 2];

                if(shooting == "success")
                {
                    cout << opponentTeam << " GOAL!" << endl;
                    opponentScore = opponentScore + 1;

                    if(opponentTeam == awayTeam)
                    {
                        awayScore = awayScore + 1;
                    }
                    else if(opponentTeam == homeTeam)
                    {
                        homeScore = homeScore + 1;
                    }

                    goal = true;
                }
                else if(shooting == "failed")
                {
                    cout << "Opponent team failed to score." << endl;

                    srand(time(NULL));
                    recovering = recoveryChance[rand() % 2];

                    if(recovering == "success")
                    {
                        cout << "Opponent team succesfully recovered the puck." << endl;
                        timeLimit = timeLimit - 1;
                    }    
                    else
                    {
                        cout << "Opponent team failed to recover the puck." << endl;
                        timeLimit = timeLimit - 1;
                        puckPossession = yourTeam;
                    }

                }
            }
            
        }

        // time manipulators
        if(timeLimit > 0 && periodNumber <= 3)
        {
            gameOver = false;
        }  
        else if(timeLimit == 0)
        {
            periodOver = true;
            if((awayScore == homeScore) && (periodNumber == 3))
            {
                gameOver = false;
                periodNumber = periodNumber + 1;
                timeLimit = 5;

            }
            else if(periodNumber < 3)
            {
                gameOver = false;
                periodNumber = periodNumber + 1;
                timeLimit = 20;
            }
        }
        else
        {
            cout << "Final Score: " << awayTeam << ": " << awayScore << " "
                 << homeTeam << ": " << homeScore << endl;
            gameOver = true;
        }
    





    }while(gameOver == false);



    return 0;
}

