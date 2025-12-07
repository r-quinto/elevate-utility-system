#include <stdio.h>
#include <conio.h>
#include <string.h>

int numdays, i;
char days[30][30];
int hours[30], minutes[30];

struct wasteType {
    char name[50];
    char category[20];
    char suggestion[100];
};


struct wasteType wasteTypes[] = {
    {"plastic", "Recyclable", "Recycle at a nearby recycling center."},
    {"paper", "Recyclable", "Place in the recycling bin."},
    {"glass", "Recyclable", "Recycle at a nearby recycling center."},
    {"food Waste", "Biodegradable", "Use for composting."},
    {"vegetables", "Biodegradable", "Use for composting."},
    {"fruits", "Biodegradable", "Use for composting."},
    {"diapers", "Non-Biodegradable", "Seal it and wrap it on a newspaper, and dispose it in the garbage bin."},
    {"sanitary napkins", "Non-Biodegradable", "Seal it and wrap it on a newspaper, and dispose it in the garbage bin."},
    {"newspaper", "Recyclable", "Place in the recycling bin."},
    {"magazines", "Recyclable", "Place in the recycling bin."},
    {"scrap metal", "Non-Biodegradable", "Bring it to a licensed landfill or incinerator that has metal waste disposal facilities."},
    {"tissue paper", "Non-Biodegradable", "Place it in your trash bin appropriately."},
    {"vegetables", "Biodegradable", "Use for composting."},
    {"old clothes", "Non-Biodegradable", "Donate, dispose, or recycle it."},
    {"milk cartons", "Recyclable", "Rinse it out and place it in the recycling bin."},
    {"plastic container", "Recyclable", "Rinse it out and place it in the recycling bin."},
    {"plastic bottle", "Recyclable", "Place it in the recycling bin."},
    {"egg cartons", "Recyclable", "Place it in the recycling bin."},
    {"can", "Recyclable", "Rinse it out and dispose at a nearby recycling center."},
    {"tissue box", "Recyclable", "Dispose in a recycling bin."},
    {"tires", "Recyclable", "Dispose at a nearby recycling center."},
    {"ceramics", "Non-Biodegradable", "Seal it and dispose it in the trash bin."},
    {"lithium battery", "Hazardous Waste", "Dispose of at designated battery collection points"},
    {"brake fluid", "Hazardous Waste", "You'll have to bring it to a waste management facility, recycle it, or evaporate it with the help of cat litter."},
    {"chemical stripper", "Hazardous Waste", "Wrap them in the newspaper, place them in a plastic bag, and dispose of them in the garbage or take them to a hazardous waste facility."},
    {"chlorine bleach", "Hazardous Waste", "Use up or give away empty bottles, and take them to a hazardous waste facility."},
    {"drain cleaner", "Hazardous Waste", "Empty containers can be disposed of in the garbage or taken to a hazardous waste facility."},
    {"fire extinguisher", "Hazardous Waste", "Recycling it when empty, dropping it off at a fire department, or taking it to a specialty disposal facility."},
    {"aerosol can", "Hazardous Waste", "Disposed of at curbside pick-up or local drop-off centers, and recycling accepted at these centers. Avoid throwing them in roadside dumps or trash fires."},
    {"herbicide", "Hazardous Waste", "Dispose of concentrated chemicals properly, following product label instructions, and only by a licensed waste disposal company or chemical collection program."},
    {"kerosene", "Hazardous Waste", "Take it to a facility for household hazardous waste (HHW) facility where it will be disposed of properly."},
    {"lighter fluid", "Hazardous Waste", "The item must be taken to a household hazardous waste disposal site or dropped off at a local hazardous waste collection event."},
    {"lye", "Hazardous Waste", "Pour cold water and slowly pour lye down the drain, wearing eye protection."},
    {"mothballs", "Hazardous Waste", "Dispose of mothballs with other households hazardous waste."},
    {"nail polish remover", "Hazardous Waste", "Deliver used nail polish and remover to a facility that handles hazardous trash."},
    {"paint", "Hazardous Waste", "Proceed to the household hazardous trash collection center in your community with the paint."},
    {"prescription drug", "Hazardous Waste", "The FDA advises disposing of unused medicines in plastic bags with undesirable substances, such as cat litter or coffee grounds, and not washing them down the sink or toilet."},
    {"solvent", "Hazardous Waste", "The containers should be tightly-capped, labeled with red hazmat tags, and designed to prevent vapor or liquid escape."}

};

void EnterCollectionSchedule() {
    printf("\n\t\tGarbage Collection Schedule\n");
    printf("\n\t\t-------------------------------------------\n");

    printf("\n\t\tEnter the number of days: ");
    scanf("%d", &numdays);

    for (i = 0; i < numdays; i++) {
        printf("\n\t\tEnter the day of collection: ");
        scanf("%s", days[i]);

        printf("\t\tEnter the time (HH:MM): ");
        scanf("%d:%d", &hours[i], &minutes[i]);
    }
}

void DisplayCollectionSchedule() {
    printf("\n\t\tCollection Schedule:\n");
    for (i = 0; i < numdays; i++) {
        printf("Day %d: %s at %02d:%02d\n", i + 1, days[i], hours[i], minutes[i]);
    }
}

void sortWaste() {
    char wasteName[50];
    int found = 0;

    getchar();

    printf("\n\t\tEnter the waste item: ");
    fgets(wasteName, sizeof(wasteName), stdin);

    wasteName[strcspn(wasteName, "\n\t\t")] = '\0';

    int numWasteTypes = sizeof(wasteTypes) / sizeof(struct wasteType);

    for (int i = 0; i < numWasteTypes; i++) {
        if (strcmp(wasteTypes[i].name, wasteName) == 0) {
            found = 1;
            printf("\t\tCategory: %s\n", wasteTypes[i].category);
            printf("\t\tSuggestion: %s\n", wasteTypes[i].suggestion);
            break;
        }
    }

    if (!found) {
        printf("\t\tWaste item not found in the classification.\n");
    }
}



void mainMenu() {
    int mainChoice, subChoice;

    printf("\n\t\tWelcome to EcoDrive!");
    printf("\n\n\t\t1. Garbage Collection Schedule");
    printf("\n\t\t2. Waste Sorting");
    printf("\n\t\t3. Exit\n");
    printf("\n\t\tEnter your choice: ");
    scanf("%d", &mainChoice);

    switch (mainChoice) {
        case 1:
            printf("\n\t\tGarbage Collection Schedule\n");
            printf("\n\t\t-------------------------------------------\n");
            printf("\n\t\t1. Add Collection Schedule");
            printf("\n\t\t2. View Collection Schedule\n");
            printf("\t\tEnter your choice: ");
            scanf("%d", &subChoice);

            switch (subChoice) {
                case 1:
                    EnterCollectionSchedule();
                    break;
                case 2:
                    DisplayCollectionSchedule();
                    break;
                default:
                    printf("\n\t\tInvalid choice. Please enter a valid option.\n");
            }
            break;

        case 2:
            printf("\n\t\tWaste Sorting");
            printf("\n\t\t----------------------------------------");
            sortWaste();
            break;
        case 3:
            printf("\t\tExiting the program. Goodbye!\n");
            break;
        default:
            printf("\n\t\tInvalid choice. Please enter a valid option.\n");
    }
}
void ebill(){
    int AC,CAN;
    float bill;
    char decide;

    printf("\t\tPlease input your Customer Account Number (CAN): ");
    scanf("%d",&CAN);
    printf("\n\t\tGood day, customer %d!",CAN);

   time_t t;
   time(&t);

   printf("\n\n\t\t%s", ctime(&t));

    printf("\n\n\n\t\tPlease input your 'Actual Consumption' in the past month of November (kWh): ");
    scanf("%d",&AC);

    printf("\n\n\t\tYour actual consumption last month is %d kWh",AC);
    printf("\n\n\t\tFor the month of November, Meralco's rate per kWh is P12.11");

    bill = AC * 12.11;

    printf("\n\n\t\tYour November bill amount should be P%0.2f",bill);

    printf("\n\n\n\t\tJust a Reminder!\n\n\t\tNext month, December 2023, your predicted electric bill amount next month is P%0.2f",AC*12.44); //dec 2022 + 0.3297

    printf("\n\n\n\n\t\tNOTE: Overall rate increase or decrease is mainly due to changes in transmission charges, generation charges, fuel cost, economy, and other charges that affects energy generation and transmission.\n\t\tPredicted monthly bill amount is based on past months' overall rate changes, economy, and energy and fuel history.");


    printf("\n\n\n\t\tDo you want to view more upcoming monthly bill amount prediction?");
    printf("\n\t\t(Type 'y' if YES and 'n' if NO): ");
    scanf(" %c",&decide);

    if (decide == 'y'){
        printf("\n\t\tYour predicted monthly bill amount for the next 12 months are as follows:");
        printf("\n\n\t\tFor January 2024:\t P%0.2f",AC*13.06);
        printf("\n\t\tFor February 2024:\t P%0.2f",AC*13.05);
        printf("\n\t\tFor March 2024:\t\t P%0.2f",AC*13.60);
        printf("\n\t\tFor April 2024:\t\t P%0.2f",AC*13.48);
        printf("\n\t\tFor May 2024:\t\t P%0.2f",AC*13.66);
        printf("\n\t\tFor June 2024:\t\t P%0.2f",AC*14.08);
        printf("\n\t\tFor July 2024:\t\t P%0.2f",AC*13.36);
        printf("\n\t\tFor August 2024:\t P%0.2f",AC*13.07);
        printf("\n\t\tFor September 2024:\t P%0.2f",AC*13.57);
        printf("\n\t\tFor October 2024:\t P%0.2f",AC*13.99);
        printf("\n\t\tFor November 2024:\t P%0.2f",AC*14.22);
        printf("\n\t\tFor December 2024:\t P%0.2f",AC*14.74);
        printf("\n\n\t\tThank you for using E-Bill!");
    }
    else
        printf("\n\t\tThank you for using E-Bill!");
}

void ComRoute(){
    int choice;
    printf("\n\n\t\tWelcome to ComRoute!");
    printf("\n\n\t\tYou are using Jeepney and headed to Bulacan State University Main Campus");
    printf("\n\t\tWhere are you from?");
    printf("\n\n\t\t1. Angat\n\t\t2. Balagtas\n\t\t3. Bocaue\n\t\t4. Baliuag\n\t\t5. Calumpit\n\t\t6. Malolos\n\t\t7. Meycauyan\n\t\t8. San Miguel\n\t\t9. Marilao\n\t\t10. Bulakan\n\t\t11. Hagonoy\n\t\t12. San Jose del Monte\n\t\t13. Guiguinto\n\t\t14. Plaridel\n\t\t15. Pulilan\n\t\t16. Norzagaray\n\t\t17. Dona Remedios Trinidad\n\t\t18. Obando\n\t\t19. Paombong\n\t\t20. Santa Maria\n\t\t21. Bustos\n\t\t22. San Rafael\n\t\t23. Pandi\n\t\t24. San Ildefonso\n");
    printf("\n\n\t\tYOUR CHOICE: ");
    scanf(" %d", &choice);
    switch(choice){
case 1:
    printf("\n \t\tFirst route:\n\t\t Angat to Baliuag = Php 15\n\t\t Baliuag to Plaridel = Php 20\n\t\t Plaridel to BulSU = Php 21\n\t\t Total Fare = Php 56");
    printf("\n \t\tYour estimated travel hours will be: 1 hours 50 minutes");
    printf("\n\n \t\tSecond route:\n\t\t Angat to Baliuag = Php 15\n\t\t Baliuag to Plaridel = Php 20\n\t\t Plaridel to Pulilan = Php 11\n\t\t Pulilan to Calumpit = Php 35\n\t\t Calumpit to Bulsu = Php 18\n\t\t Total Fare = Php 99");
    printf("\n \t\tYour estimated travel hours will be: 1 hour 40 minutes");
    printf("\n\n\t\tSuggested Route: First Route"); break;
case 2:
    printf("\n \t\tYour route: (One Way)\n\t\t Balagtas to BulSU = Php 20\n\t\t Total Fare = Php 20");
    printf("\n \t\tYour estimated travel hours will be: 35 minutes"); break;
case 3:
    printf("\n \t\tYour route: (One Way)\n\t\t Bocaue to BulSU = Php 30\n\t\t Total Fare = Php 30");
    printf("\n \t\tYour estimated travel hours will be: 45 minutes"); break;
case 4:
    printf("\n \t\tFirst route:\n\t\t Baliuag to Plaridel = Php 20\n\t\t Plaridel to BulSU = Php 21\n\t\t Total Fare = Php 41");
    printf("\n \t\tYour estimated travel hours will be: 45 minutes");
    printf("\n\n \t\tSecond route:\n\t\t Baliuag to Plaridel = Php 20\n\t\t Plaridel to Pulilan = Php 11\n\t\t Pulilan to Calumpit = Php 35\n\t\t Calumpit to BulSU = Php 18\n\t\t Total Fare = Php 84");
    printf("\n \t\tYour estimated travel hours will be: 1 hour 20 minutes");
    printf("\n\n\t\tSuggested Route: First Route"); break;
case 5:
    printf("\n \t\tYour route:(One Way)\n\t\t Calumpit to BulSU = Php 18\n\t\t Total Fare = 18");
    printf("\n \t\tYour estimated travel hours will be: 20 minutes"); break;
case 6:
    printf("\n \t\tYour route:(One Way)\n\t\t Malolos to BulSU = Php 11\n\t\t Total Fare = Php 11");
    printf("\n \t\tYour estimated travel hours will be: 15 minutes"); break;
case 7:
    printf("\n \t\tYour route:(One Way)\n\t\t Meycauyan to BulSU = Php 46\n\t\t Total Fare = Php 46");
    printf("\n \t\tYour estimated travel hours will be: 1 hour 10 minutes"); break;
case 8:
    printf("\n \t\tFirst route:\n\t\t San Miguel to Plaridel = Php 60\n\t\t Plaridel to Pulilan = Php 11\n\t\t Pulilan to Calumpit = Php 35\n\t\t Calumpit to BulSU = Php 13\n\t\t Total Fare = Php 119");
    printf("\n \t\tYour estimated travel hours will be: 2 hours 13 minutes");
    printf("\n\n \t\tSecond route:\n\t\t San Miguel to Plaridel = Php 60\n\t\t Plaridel to BulSU = Php 21\n\t\t Total Fare = Php 81");
    printf("\n \t\tYour estimated travel hours will be: 1 hr 57 minutes");
    printf("\n\n\t\tSuggested Route: Second Route"); break;
case 9:
    printf("\n \t\tYour route:(One Way)\n\t\t Marilao to BulSU = Php 35\n\t\t Total Fare = Php 35");
    printf("\n \t\tYour estimated travel hours will be: 1 hour"); break;
case 10:
    printf("\n \t\tYour route:(One Way)\n\t\t Bulakan to Malolos = Php 21\n\t\t Malolos to BulSU = Php 11\n\t\t Total Fare = Php 32");
    printf("\n \t\tYour estimated travel hours will be: 1 hour"); break;
case 11:
    printf("\n \t\tYour route:(One Way)\n\t\t Hagonoy to BulSU = Php 21\n\t\t Total Fare = Php 21");
    printf("\n \t\tYour estimated travel hours will be: 1 hour"); break;
case 12:
    printf("\n \t\tYour route:(One Way)\n\t\t San Jose del Monte to BulSU = Php 45\n\t\t Total Fare = 45");
    printf("\n \t\tYour estimated travel hours will be: 1 hour"); break;
case 13:
    printf("\n \t\tYour route:(One Way)\n\t\t Guiguinto to BulSU = Php 13\n\t\t Total Fare = Php 13");
    printf("\n \t\tYour estimated travel hours will be: 30 minutes"); break;
case 14:
    printf("\n \t\tFirst route:\n\t\t Plaridel to BulSU = Php 21\n\t\t Total Fare = Php 21");
    printf("\n \t\tYour estimated travel hours will be: 30 minutes");
    printf("\n\n \t\tSecond Route:\n\t\t Plaridel to Pulilan = Php 11\n\t\t Pulilan to Calumpit = Php 35\n\t\t Calumpit to BulSU = Php 18\n\t\t Total Fare = Php 64");
    printf("\n \t\tYour estimated travel hours will be: 53 minutes");
    printf("\n\n\t\tSuggested Route: First Route"); break;
case 15:
    printf("\n \t\tFirst Route:\n\t\t Pulilan to Calumpit = Php 35\n\t\t Calumpit to BulSU = Php 18\n\t\t Total Fare = Php 53");
    printf("\n \t\tYour estimated travel hours will be: 50 minutes");
    printf("\n\n \t\tSecond route:\n\t\t Pulilan to BulSU = Php 21\n\t\t Total Fare = Php 21");
    printf("\n \t\tYour estimated travel hours will be: 45 minutes");
    printf("\n\n\t\tSuggested Route: Second Route"); break;
case 16:
    printf("\n \t\tFirst route:\n\t\t Norzagaray to Angat = Php 20\n\t\t Angat to Baliuag = Php 15\n\t\t Baliuag to Plaridel = Php 20\n\t\t Plaridel to Pulilan = Php 11\n\t\t Pulilan to Calumpit = Php 35\n\t\t Calumpit to BulSU = Php 18\n\t\t Total Fare = Php 119");
    printf("\n \t\tYour estimated travel hours will be: 2hours 10 minutes");
    printf("\n\n \t\tSecond route:\n\t\t Norzagaray to Angat = Php 20\n\t\t Angat to Baliuag = Php 15\n\t\t Baliuag to Plaridel = Php 20\n\t\t Plaridel to Bulsu = Php 21\n\t\t Total Fare = Php 76");
    printf("\n \t\tYour estimated travel hours will be: 1 hour 30 minutes");
    printf("\n\n\t\tSuggested Route: Second Route"); break;
case 17:
    printf("\n \t\tYour route:\n\t\t Dona Remedios Trinidad to BulSU = Unknown");
    printf("\n \t\tYour estimated travel hours will be: Unknown"); break;
case 18:
    printf("\n \t\tYour route:(One Way)\n\t\t Obando to Bulakan = Php 25\n\t\t Bulakan to Malolos = Php 21\n\t\t Malolos to Bulsu = Php 11\n\t\t Total Fare = Php 57");
    printf("\n \t\tYour estimated travel hours will be: 1 hour 20 minutes"); break;
case 19:
    printf("\n \t\tYour route:(One Way)\n\t\t Paombong to Malolos = Php 11\n\t\t Malolos to Bulsu = Php 11\n\t\t Total Fare = Php 22");
    printf("\n \t\tYour estimated travel hours will be: 45 minutes"); break;
case 20:
    printf("\n \t\tYour route:(One Way)\n\t\t Santa Maria to BulSU = Php 40\n\t\t Total Fare = Php 40");
    printf("\n \t\tYour estimated travel hours will be: 1 hour"); break;
case 21:
    printf("\n \t\tFirst route:\n\t\t Bustos to Baliuag = Php 15\n\t\t Baliuag to Plaridel = Php 20\n\t\t Plaridel to Pulilan = Php 11\n\t\t Pulilan to Calumpit = Php 35\n\t\t Calumpit to BulSU = Php 18\n\t\t Total Fare = Php 99");
    printf("\n \t\tYour estimated travel hours will be: 2 hours");
    printf("\n\n \t\tSecond route:\n\t\t Bustos to Baliuag = Php 15\n\t\t Baliuag to Plaridel = Php 20\n\t\t Plaridel to BulSU = Php 21\n\t\t Total Fare = Php 56");
    printf("\n \t\tYour estimated travel hours will be: 1 hour");
    printf("\n\n\t\tSuggested route: Second Route"); break;
case 22:
    printf("\n \t\tFirst route:\n\t\t San Rafael to Baliuag = Php 25\n\t\t Baliuag to Plaridel = Php 20\n\t\t Plaridel to BulSU = Php 21\n\t\t Total Fare = Php 66");
    printf("\n \t\tYour estimated travel hours will be: 1 hour");
    printf("\n\n \t\tSecond route:\n\t\t San Rafael to Baliuag = Php 25\n\t\t Baliuag to Plaridel = Php 20\n\t\t Plaridel to Pulilan = Php 11\n\t\t Pulilan to Calumpit = Php 35\n\t\t Calumpit to BulSU = Php 18\n\t\t Total Fare = Php 109");
    printf("\n \t\tYour estimated travel hours will be: 2 hours 5 minutes");
    printf("\n\n\t\tSuggested Route: First Route"); break;
case 23:
    printf("\n \t\tYour route:\n\t\t Pandi to BulSU = Unknown");
    printf("\n \t\tYour estimated travel hours will be: Unknown"); break;
case 24:
    printf("\n \t\tYour route:\n\t\t San Ildefonso to BulSU = Unknown");
    printf("\n \t\tYour estimated travel hours will be: Unknown"); break;
default:
    printf("\t\tInvalid Input\n");
    }
}

int main()
{
    int c1;
    char done, user[50];

    do{

    printf("\t\t__________________________________________________________________\n");
    printf("\n\t\t *******  *        *******  *       *  *     *******  ******* ");
    printf("\n\t\t *        *        *         *     *  * *       *     * ");
    printf("\n\t\t ******   *        ******     *   *  *   *      *     ****** ");
    printf("\n\t\t *        *        *           * *  *******     *     * ");
    printf("\n\t\t *******  *******  *******      *  *       *    *     ******* ");
    printf("\n\t\t__________________________________________________________________");

    printf("\n\n\t\tGOOD DAY!\n\t\tWhat is your name? ");
    scanf(" %s", &user);

    printf("\n\n\t\tWelcome %s! \n\t\tTHIS IS ELEVATE!", user);
    printf("\n\n\t\tPLEASE CHOOSE:\n\n \t\t1. Ecodrive\n \t\t2. E-Bill\n \t\t3. ComRoute\n");
    printf("\n\t\tYOUR CHOICE: ");
    scanf(" %d", &c1);

    switch(c1){
    case 1:
        //EcoDrive();
        mainMenu();
        break;

    case 2:
        ebill();
        break;

    case 3:
        ComRoute();
        break;

    default:
    printf("\n\n\t\tInvalid!");
    }
    printf("\n\n\t\tDo you want to try again? ");
    scanf(" %c", &done);
    } while(done != 'N');
    return 0;
}

