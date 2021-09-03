/**
 *  Creator:    Sean Horner
 *  Created:    05.15.2020
 *  Updated:    06.05.2020
 *  Purpose:    This is the code for a simple math game where the user must guess a
 *              combination of randomly generated integers (increasing in range and
 *              number as the player succeeds).
 *  Require:    none
 **/

#include <iostream>
#include <ctime>
#include <random>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;


void clearScreen();
void game(int);
void success(int);
void failure(int);

int main()
{
    // Vectors of integers to hold the numbers and guesses lists
    vector<int> nums;
    vector<int> guesses;
    
    // Integers for the level number, sum, product, and guess
    int level = 1;
    int sum = 0;
    int prod = 1;
    int guess = 0;

    // Boolean for if the attempt succeeded
    bool proceed = true;

    // Random number generator is seeded by the current time
    srand(time(0));

    do
    {   
        // Present intial level text
        game(level);

        // Picking the random numbers for the level
        for(int h = 0; h <= level; h += 2)
            {nums.push_back(1 + rand() % level);}

        // Sorting the nums list with std::sort from the <algorithm> header
        sort(nums.begin(), nums.end());

        // Reinitializing and calculating the product of the numbers in the vector
        prod = 1;
        for (int i = 0; i < nums.size(); i++)
            {prod *= nums[i];}

        // Reinitializing and calculation the sum of the numbers in the vector
        sum = 0;
        for (int j = 0; j < nums.size(); j++)
            {sum += nums[j];}

        // Presenting the parameters to the player: number, sum, and product
        cout << "~ There are " << nums.size() << " numbers" << "\n"
             << "~ The sum of the numbers is " << sum << "\n"
             << "~ The product of the numbers is " << prod << "\n" << endl;

        // Prompting the player for guesses
        cout << "*The screen displays another message: * \n"
             << "Enter your " << nums.size() << " guesses (space separated): ";
        
        // Getting the appropriate number of inputs from the player
        for (int k = 0; k < nums.size(); k++)
        {
            cin >> guess;
            guesses.push_back(guess);
        }

        // Clearing the cin stream
        cin.ignore(20, '\n');

        // Formatting after input and clearing the buffer
        cout << "\n" << endl;

        // Sorting the guesses list with std::sort from the <algorithm> header
        sort(guesses.begin(), guesses.end());


        // Test for vector equivalence, i.e. guesses are correct
        for (int l = 0; l < nums.size(); l++)
        {
            if (nums[l] != guesses[l])
                {proceed = false;}
        }

        // Clearing the nums and guesses vectors for next run
        nums.clear();
        guesses.clear();

        // If the vectors are identical
        if (proceed)
        {   // Presenting player with the level's successful completion text
            success(level);
            level++;
        } else {
            // Presenting player with a failure message unique to the level
            failure(level);
            
            // char variable to store player answer
            char a = '';
            
            // Prompting player for a reset
            cout << "Play again? (y/n): ";
            cin >> a;
            cout << endl;

            // 
            if (char == 'y' || char == 'Y')
            {
                level = 1;
                proceed = true;
            }
        }

    // Continue running as long as the proceed flag is true or the current level less than 5.
    } while (proceed && level <= 5);

    return 0;
}

// Text generating function for each level's initial text
void game(int level)
{
    // Initial formatting spacing
    cout << "\n\n";

    switch(level)
    {
        case 1:
            // First level message: Gazorpazorp
            cout << "* As you burst out of the portal, you enter a dimmly lit room,\n"
                 << "* LEDs and text displays glow in the dark. You see Rick engaged\n"
                 << "* in dire battle with an enraged Gazorpazorpian!\n\n"
                 << "Rick:  Quick! Morty! These Gazorpazorpians are real f*ckin idiots!\n"
                 << "       The code is probably written down somewhere!\n\n"
                 << "Morty: Oh crap, Rick! Okay, um, uh...\n\n"
                 << "* You quickly glance around and see a conspicuous Post-It note on\n"
                 << "* one of the computers. It reads:\n" << endl;
            break;
        case 2:
            // Second level message: Intergalactic Federation base
            cout << "* As you spill out of that portal, you hear laser blasts all around\n"
                 << "* you! You've tumbled into a full-on brawl aboard an Intergalactic\n"
                 << "* Federation base station!\n\n"
                 << "Rick:  Damn! Morty, I'm pinned down! See if you can\n"
                 << "       roll over to the console and--\n\n"
                 << "* Suddenly a blast rips through the metal just next to Rick's ear,\n"
                 << "* cutting him off.\n\n"
                 << "Morty: Aw, geez, Rick! There's like 50 guys trying to shoot us!\n"
                 << "       What if I get shot?!\n\n"
                 << "Rick:  Well then let's make it easy! If you don't do it, I will\n"
                 << "       shoot you!\n\n"
                 << "* You'd like to think that Rick is being overly-dramatic, but that\n"
                 << "* didn't sound very sarcastic. During a brief lull in the firing\n"
                 << "* (reloading, you hope) you dive for the console. Successfully there,\n"
                 << "* you read:\n" << endl;
            break;
        case 3:
            // Third level message: the Vindicators' space station
            cout << "* You spill out of the portal into yet another dimly-lit room. But\n"
                 << "* this one does seem familiar to you...\n\n"
                 << "Morty: Rick? Rick?\n"
                 << "Rick:  Morty! Watch out!\n\n"
                 << "* Just as Rick shouts, a tiny galaxy shoots past your head with a woosh.\n"
                 << "* Suddenly you feel an invisible grip wrap around your throat. Scanning\n"
                 << "* the room for your assailant you suddenly lock eyes with two glowing,\n"
                 << "* purple orbs in the corner of the room. It's Supernova! Rick rolls out\n"
                 << "* from his hiding place and hits her flank with a blast of science-y\n"
                 << "* light. You feel the invisible grip disappear.\n\n"
                 << "Rick:  Quick, Morty! The console over there.\n\n"
                 << "* Rick points to a nearby console. You know the drill, you make your way\n"
                 << "* over as quickly as possible while avoiding the mayhem spewing from the\n"
                 << "* Rick-Supernova clash.\n" << endl;
            break;
        case 4:
            // Fourth level message: Old Man/the Devil's shop [Sphinx]
            cout << "* You both fall out of the portal nearly simultaneously. This room is\n"
                 << "* dusty and full of wodden shelves covered with random minutae...\n\n"
		         << "Devil: Well hello Rick, so we meet again...\n\n"
		         << "* The Devil slowly hobbles out from a shadow, aided by a cane. His face\n"
		         << "* twisting torturously with every step.\n\n"
		         << "Rick:  Oh damn! I thought you'd like super heal yourself or something\n"
		         << "       after we messed you up.\n"
		         << "Devil: I only get so many mortal coils per century, I'm not going to\n"
		         << "       waste this one just because you put a few dents in it.\n\n"
		         << "* You decide to leave the two to catch up search out the console you\n"
		         << "* know must be here. You begin searching the room, but everything in\n"
		         << "* here is an antique. You don't see a computer screen anywhere. About\n"
		         << "* to give up, you notice something odd. Hanging in the air above a nearby\n"
		         << "* type writer, is if typed on invisible paper, you see:\n" << endl;
            break;
        case 5:
            // Final level message: the Zigerion scammers' VR machine
            cout << "Fifth level message\n" << endl;
            break; 
        default:
            cout << "How did you get here?\n" << endl;
    }

}

// Text generating function for each level's successful completion
void success(int level)
{
    switch(level)
    {
        case 1:
            // First level success message
            cout << "* Success! The computer logs in just as Rick finally bests the\n"
                 << "* battle-hardened Gazorpgazorpian. He leaps over to your side of the\n"
                 << "* hovel and enters a couple lines of code.\n\n"
                 << "Rick:  Alright Morty, on to the next junction point!\n"
                 << "Morty: Right! Wait... what are we doing again?\n"
                 << "Rick:  Dammit, Morty! There's no time!--\n\n"
                 << "* Rick shouts as he opens an immediately jumps through another portal.\n"
                 << "* Aw geez you think as you scramble after him.\n" << endl;
            break;
        case 2:
            // Second level success message
            cout << "* Success! You're logged in! After Rick mops up the rest of the Federation\n"
                 << "* soldiers, he jogs over to the console and enters a few commands.\n\n"
                 << "Rick:  Excellent, Morty! Really, just a real *burp* bang-up job!\n"
                 << "       On to the next one!\n\n"
                 << "* Rick opens another portal and leaps through.\n\n"
                 << "Morty: Wait! Rick! Damnit, what's going on?\n\n"
                 << "* You reluctantly follow Rick through the portal.\n" << endl;
            break;
        case 3:
            // Third level success message
            cout << "* Success! The console logs into the server. You turn around in time to see\n"
                 << "* Rick being menaced by Supernova with a microsized Jupiter, his portal gun\n"
		         << "* a few feet out of his reach. Just before she brings the microplanet down to\n"
		         << "* crush Rick, you shout\n\n"
		         << "Morty: Uh - hey- uh- Supernova, what can kill a galaxy?\n\n"
		         << "* As she turns in your direction, her expression changes from one of conquest\n"
		         << "* to one of apprehension as she sees you holding the portal gun.\n\n"
		         << "Morty: A blackhole!\n\n"
		         << "* You shout as you launch a portal right behind her to what you're pretty sure\n"
		         << "* is the all blackholes dimension. Or maybe it's the dimension where everybody\n"
		         << "* takes really deep breaths. Either way, in spinning to look at the portal, Supernova's\n"
		         << "* hand passes through the barrier, causing her to be sucked inside!\n\n"
		         << "Rick: Nicely done, Morty! Only two more to go!\n\n"
		         << "* Rick takes his portal gun, opens a new portal and hops through. As you follow after him\n"
		         << "* you wonder how long your portal will remain open and if it might accidently eat up\n"
		         << "* anything else. Oh well, no time for that now.\n" << endl; 
            break;
        case 4:
            // Fourth level success message
            cout << "Fourth success message!\n" << endl; 
            break;
        case 5:
            // Final level success message
            cout << "Morty: Okay, now *this* seems really weird Rick, are we in a dream?\n"
                 << "Rick:  Yes Morty, it would seem that as in all poorly-written fiction,\n"
                 << "       we're just now coming out of a Dallas-esque \"everything is okay\"\n" 
                 << "       dream sequence What a load!\n\n"
                 << "* Slowly you feel your eyes begin to open. Yup, you're in your bed, in your\n"
                 << "* pajamas, and running 10 minutes late for school! \"Aw geez!\" you shout\n"
                 << "* as you run down the stairs half-dressed. Slowly, Rick rises from his\n"
                 << "* hiding place below your bed, removing a Dreamalizer from his ear.\n\n"
                 << "Congratulations, you beat my ridiculous game! Please let me know if you\n"
                 << "liked it, and feel free to fork it into your own version, just let me\n"
                 << "know so I can try it :D!" << endl;
            break;
        default:
            cout << "How did you get here?\n" << endl;
    }
}

void failure(int level)
{
    switch(level)
    {
        case 1:
            // First level failure message
            cout << "* Wrong! The computer shuts down with a loud siren: you've tripped the alarm.\n"
                 << "* Rick turns his head to chastise you for your idiocy when suddenly the tip of a\n"
                 << "* Gazorpzgazorpian spear bursts forth from Rick's face, speared by another\n"
                 << "* warrior entering the room.\n" << endl; 
            break;
        case 2:
            // Second level failure message
            cout << "* Failure! Through a screaming siren, the console declares:\n\n"
                 << "Console:  Incorrect password entry, self-destruct mechanism activated,\n"
                 << "          detonating in two--\n"
                 << "Morty:    wait wha--?!\n"
                 << "Console:  One. Destruct--\n\n"
                 << "* The computer console explodes, rending a hole in the exterior hull,\n"
                 << "* sucking you, Rick, and a good number of Federation soldiers out into the\n"
                 << "* endless void.\n" << endl;
            break;
        case 3:
            // Third level failure message
            cout << "* Failure! But the console offers you another chance. It reads:\n\n"
                 << "*** To try again, press enter ***\n\n"
                 << "* As you go to press the enter key, a softball size comet whips past your head\n"
                 << "* straight into the console screen. As the console showers you in sparks,\n"
                 << "* you turn to Rick. As soon as you do, you feel the invisible hand at your\n"
                 << "* throat again, this time much stronger and much more sure of your demise.\n"
                 << "* You slowly feel the world go dark as you hear Supernova's cackle ring\n"
                 << "* in your ears...\n" << endl;
            break;
        case 4:
            // Fourth level failure message
            cout << "* Wrong! The console disappears in a puff of smoke! You turn to Rick to\n"
		         << "* protest, but he's not there! Nor is the Devil?! In fact, there's nothing\n"
		         << "* at all in the room. There is no room. You're suddenly in an inky black\n"
		         << "* void, surrounded by nothingness. The Devil has banished you to the void!\n" << endl;
            break;
        case 5:
            // Final level failure message
            cout << "* Sirens begin blaring. Suddenly, you snap awake in your bed. Wait, what?\n"
                 << "* you think to yourself. Was it all a dream? Well that doesn't matter right\n"
                 << "* now because school started 10 minutes ago! You launch yourself out of bed\n"
                 << "* looking for your one clean shirt: the yellow one. Throwing it on, you run\n"
                 << "* out the door, snagging your backpack on the way out. Hopefully today will\n"
                 << "* be a normal day, you think. The algorithm says you will.\n" << endl; 
            break;
        default:
            cout << "How did you get here?\n" << endl;
    }
}