#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

#include "restaurant.h"

int main() {
  float subtotal = 20;
  float tax, total;
  int length;
  string userAppetizer, userEntree1, userEntree2;

  string appetizers[] = {
    "Two Caesar Side Salads                   (800 Cal.)",
    "Spinach + Artichoke Dip                  (960 Cal.)",
    "Crunchy Onion Rings                      (1300 Cal.)",
    "Boneless Wings                           (1160 Cal.)",
    "Mozzarella Sticks                        (910 Cal.)"
  };

  string entrees[] = {
    "Chicken Tenders Basket                   (1150 Cal.)",
    "Oriental Chicken Salad                   (1420 Cal.)",
    "Firecracker Shrimp Cavatappi             (1970 Cal.) [Plus 3.50]",
    "The American Standard                    (1010 Cal.)",
    "Blackened Tilapia                        (510 Cal.)",
    "Whisky Bacon Burger                      (1240 Cal.)",
    "Double-Glazed Baby Back Ribs - Half Rack (550 Cal.) [Plus 3.50]",
    "Cedar Grilled Lemon Chicken              (580 Cal.)",
    "Fiesta Lime Chicken                      (1140 Cal.)",
    "Three-Cheese Chicken Cavatappi           (1280 Cal.)"
  };

  menuA();
  length = end(appetizers) - begin(appetizers);
  choice(appetizers, length, userAppetizer);

  menuB();
  length = end(entrees) - begin(entrees);
  choice(entrees, length, userEntree1);
  choice(entrees, length, userEntree2);

  subtotal = getCalculate(subtotal, tax, total, entrees, userEntree1, userEntree2);

  receipt(userAppetizer, userEntree1, userEntree2, subtotal, tax, total);
  return 0;
}
