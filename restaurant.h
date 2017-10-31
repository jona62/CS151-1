#ifndef RESTAURANT_H
#define RESTAURANT_H

#define length(array) (sizeof(array)/sizeof(array[0]))

void menuA() {
    cout << "Applebee’s Two for Twenty\n";
    cout << "Two Entrees + One Appetizer\n\n";
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

string choice(string menu[], int lengthOflist, string& item) {
  int menuNumber;
    getline(cin, item);
    stringstream(item) >> menuNumber;
    if (menuNumber <= lengthOflist)
    {
      item = menu[menuNumber - 1];
    } else {
      item = menu[0];
    }
  return item;
  }


float getCalculate(float subtotal, float& tax, float& total, string entree[], string entree1, string entree2) {
  tax = ( subtotal - (subtotal * 0.887) );
  total = ( subtotal + tax );

  if (entree1 == entree[2] || entree1 == entree[6]) {
    subtotal += 3.5;
  }
  if (entree2 == entree[2] || entree2 == entree[6]) {
    subtotal += 3.5;
  }
  return subtotal;
}

void receipt(string appetizer, string entree1, string entree2, float subtotal, float tax, float total) {
  ofstream writeReceipt;
  ifstream readReceipt;

  writeReceipt.open("receipt.txt");

  if (writeReceipt.is_open()) {
    writeReceipt << fixed << setprecision(2);
    writeReceipt << "                      RECEIPT\n";
    writeReceipt << "Appetizer:" << "........................" << appetizer << endl;
    writeReceipt << "First Entree:" << "....................." << entree1 << endl;
    writeReceipt << "Second Entree:" << "...................." << entree2 << endl;
    writeReceipt << "Subtotal:" << "........................." << subtotal << endl;
    writeReceipt << "Tax:" << ".............................." << tax << endl;
    writeReceipt << "Total:" << "............................" << total << endl;
    writeReceipt << "Gratuity Guidelines:" << endl;
    writeReceipt << "15%..............................." << (subtotal * 0.15) << endl;
    writeReceipt << "18%..............................." << (subtotal * 0.18) << endl;
    writeReceipt << "20%..............................." << (subtotal * 0.20) << endl;
    writeReceipt.close();
  }

  readReceipt.open("receipt.txt");
  if (readReceipt.is_open()) {
    cout << readReceipt.rdbuf() << endl;
    readReceipt.close();
  }

}

#endif //RESTAURANT_H
