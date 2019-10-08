#include <iostream>
#include <string>
using namespace std;




string determineSubstance(double bp){

    const double WATER_BP = 100;
    const double MERC_BP = 357;
    const double COPPER_BP = 1187;
    const double SILVER_BP = 2193;
    const double GOLD_BP = 2660;

    if(bp >= (WATER_BP*.95) && bp <= (WATER_BP*1.05))
        return "Water";
    else if(bp >= (MERC_BP*.95) && bp <= (MERC_BP*1.05))
        return "Mercury";
    else if(bp >= (COPPER_BP*.95) && bp <= (COPPER_BP*1.05))
        return "Copper";
        else if(bp >= (SILVER_BP*.95) && bp <= (SILVER_BP*1.05))
        return "Silver";
        else if(bp >= (GOLD_BP*.95) && bp <= (GOLD_BP*1.05))
        return "Gold";
    else{
        return "Unknown";
    } }

int main(){
    double bp;
    string ans;
    cout<<"Enter bp: "<<endl;
    cin>>bp;
    ans = determineSubstance(bp);
    cout<<ans<<endl;

    return 0;
}
