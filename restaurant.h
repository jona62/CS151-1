#ifndef RESTAURANT_H
#define RESTAURANT_H


void menuA() {
    cout << "Appetizers:\n";
    cout << "1:  Two Caesar Side Salads                   (800 Cal.)\n";
    cout << "2:  Spinach + Artichoke Dip                  (960 Cal.)\n";
    cout << "3:  Crunchy Onion Rings                      (1300 Cal.)\n";
    cout << "4:  Boneless Wings                           (1160 Cal.)\n";
    cout << "5:  Mozzarella Sticks                        (910 Cal.)\n";
    cout << "What would you like? Please choose by number:\n";
}

void menuB() {
    cout << "Entrees:\n";
    cout << "1:  Chicken Tenders Basket                   (1150 Cal.)\n";
    cout << "2:  Oriental Chicken Salad                   (1420 Cal.)\n";
    cout << "3:  Firecracker Shrimp Cavatappi             (1970 Cal.) [Plus 3.50]\n";
    cout << "4:  The American Standard                    (1010 Cal.)\n";
    cout << "5:  Blackened Tilapia                        (510 Cal.)\n";
    cout << "6:  Whisky Bacon Burger                      (1240 Cal.)\n";
    cout << "7:  Double-Glazed Baby Back Ribs - Half Rack (550 Cal.) [Plus 3.50]\n";
    cout << "8:  Cedar Grilled Lemon Chicken              (580 Cal.)\n";
    cout << "9:  Fiesta Lime Chicken                      (1140 Cal.)\n";
    cout << "10: Three-Cheese Chicken Cavatappi           (1280 Cal.)\n";
    cout << "What would you like? Please choose two items by number:\n";
}

string choiceA(string appetizer[], string& item) {
  int menuNumber;
    getline(cin, item);
    stringstream(item) >> menuNumber;

    if (menuNumber >= 1 && menuNumber <= 10)
    {
      item = appetizer[menuNumber - 1];
    }
    else { item = appetizer[0]; }

  return item;
  }

string choiceB(string entree[], string& item) {
  int menuNumber;
    getline(cin, item);
    stringstream(item) >> menuNumber;

      if (menuNumber >= 1 && menuNumber <= 10)
      {
        item = entree[menuNumber - 1];
      }
      else { item = entree[0]; }

  return item;
}

float getSubtotal(float subtotal, string entree[], string entree1, string entree2) {
  if (entree1 == entree[2] || entree1 == entree[6]) {
    subtotal += 3.5;
  }
  if (entree2 == entree[2] || entree2 == entree[6]) {
    subtotal += 3.5;
  }
  return subtotal;
}

float getTax(float subtotal) {
  return ( subtotal - (subtotal * 0.887) );
}

float getTip(float subtotal, float percentage) {
  return (subtotal * percentage);
}

float getTotal(float subtotal, float tax) {
  return ( subtotal + tax );
}

void receipt(string appetizer, string entree1, string entree2, float subtotal, float tax, float total) {
  cout << fixed << setprecision(2);
  //string bill = "";
  //stringstream push;
  cout << "Appetizer:" << "........................" << appetizer << endl;
  cout << "First Entree:" << "....................." << entree1 << endl;
  cout << "Second Entree:" << "...................." << entree2 << endl;
  cout << "Subtotal:" << "........................." << subtotal << endl;
  cout << "Tax:" << ".............................." << tax << endl;
  cout << "Total:" << "............................" << total << endl;
  cout << "Gratuity Guidelines:" << endl;
  cout << "15%..............................." << getTip(subtotal, 0.15) << endl;
  cout << "18%..............................." << getTip(subtotal, 0.18) << endl;
  cout << "20%..............................." << getTip(subtotal, 0.20) << endl;
  //push >> bill >> bill >> bill >> bill >> bill >> bill >> bill >> bill >> bill;
  //cout << bill;
}

#endif //RESTAURANT_H
