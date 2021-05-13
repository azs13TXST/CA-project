#include <iostream>
#include <list>
using namespace std;
class HashMapTable {
// size of the hash table
  int table_size;
// Pointer to an array containing the keys
  list<int> *table;
  public:
// creating constructor of the above class containing all the methods
HashMapTable(int key);
// hash function to compute the index using table_size and key
  int hashFunction(int key) {
    return (key % table_size);
  }
// inserting the key in the hash table
  void insertElement(int key);
// deleting the key in the hash table
  void deleteElement(int key);
// displaying the full hash table
  void displayHashTable();
};

//creating the hash table with the given table size
HashMapTable::HashMapTable(int  ts)  {
  this->table_size = ts;
  table = new list<int>[table_size];
}

// insert function to push the keys in hash table
void HashMapTable::insertElement(int key)  {
  int index = hashFunction(key);
  table[index].push_back(key);
}

// delete function to delete the element from the hash table
void HashMapTable::deleteElement(int key)  {
  int index = hashFunction(key);
// finding the key at the computed index
  list <int> :: iterator i;
  for (i = table[index].begin(); i != table[index].end(); i++)  {
    if (*i == key)
    break;
  }
// removing the key from hash table if found
  if (i != table[index].end())
    table[index].erase(i);
}

// display function to showcase the whole hash table
void HashMapTable::displayHashTable() {
  for (int i = 0; i<table_size; i++) {
    cout<<i;
// traversing at the recent/ current index
    for (int j : table[i]) 
      cout << " ==> " << j;

     cout << endl;
  }
}

// Main function
int main()  {
// array of all the keys to be inserted in hash table
  int arr[] = {20, 34, 56, 54, 76, 87, 23, 34, 24, 34, 64, 24 ,85, 38, 94, 192, 128, 1, 182, 14, 23, 43, 83, 904, 384, 934, 283, 8273, 182, 73, 283, 947, 283, 341, 827, 905, 273, 9185, 26374, 69, 273,2829, 9012, 8273, 72634, 2938, 28537, 27849, 28365, 2836, 7254, 93464, 234689, 986432, 43892, 84763, 2789, 3072, 16666, 21214, 30341, 37980, 67133, 86709, 95167, 105804, 114189, 115389, 117378, 127650, 128847, 131321, 138486, 160663, 164376, 181682, 186816, 205728, 238150, 238989, 253134, 253602, 258080, 261401, 262226, 268180, 269704, 275963, 285057, 285131, 286523, 289645, 290740, 295719, 332589, 334003, 338341, 343875, 351444, 353620, 355877, 370200, 371322, 374885, 375133, 379814, 384057, 388787, 401621, 407044, 417971, 448323, 449146, 465952, 473462, 481711, 499177, 513092, 514866, 518541, 521841, 524182, 525611, 551541, 560252, 570479, 578477, 589292, 590360, 617349, 631411, 638450, 661832, 671432, 691463, 693099, 709191, 714780, 721489, 740278, 744149, 745264, 751409, 762114, 763624, 767146, 767812, 777198, 799299, 812204, 822432, 831187, 842830, 883982, 886307, 892785, 1346, 7022, 14928, 29813, 32298, 32467, 82843, 91407, 101772, 104309, 114330, 117577, 129648, 130620, 143882, 171384, 173453, 190491, 190938, 197315, 199543, 200221, 215363, 215570, 227226, 229790, 247759, 255634, 259585, 266455, 273839, 288417, 294893, 295033, 322580, 329484, 339461, 345548, 359049, 370512, 393251, 411284, 428861, 436151, 437900, 438115, 439788, 460300, 471289, 472883, 493029, 493867, 499878, 502615, 505880, 507816, 521446, 532112, 540255, 547342, 570778, 583907, 593914, 596236, 597838, 611123, 618788, 630486, 635210, 644014, 644726, 660742, 669928, 679493, 702688, 710994, 718001, 735518, 738052, 749254, 750521, 762552, 769462, 784444, 786251, 817204, 820232, 826545, 826697, 828341, 832840, 834228, 841566, 841903, 849756, 857866, 872268, 877949, 880260, 899321, 38, 59, 145, 263, 287, 532, 567, 607, 663, 780, 997, 1100, 1224, 1323, 1365, 1490, 1655, 2010, 2155, 2287, 2298, 2389, 2445, 2552, 2571, 2733, 2741, 2770, 2781, 2814, 3060, 3158, 3197, 3228, 3308, 3422, 3450, 3615, 3703, 3873, 3923, 4341, 4368, 4394, 4474, 4487, 4488, 4528, 4737, 5054, 5132, 5144, 5177, 5230, 5730, 5814, 5836, 6093, 6110, 6205, 6227, 6242, 6399, 6437, 6673, 6824, 6967, 6993, 7031, 7161, 7171, 7261, 7343, 7391, 7626, 7649, 7696, 7704, 7757, 7774, 7775, 7798, 7968, 8018, 8081, 8125, 8126, 8272, 8290, 8367, 8415, 8434, 8442, 8567, 8582, 8739, 8896, 9640, 9750, 9966, 25, 135, 315, 321, 398, 430, 469, 496, 515, 583, 667, 865, 888, 929, 1041, 1120, 1244, 1489, 1519, 1523, 1555, 1824, 1917, 1926, 2013, 2304, 2458, 2487, 2510, 2703, 2726, 2876, 2982, 3367, 3473, 3679, 3693, 3772, 3945, 4063, 4378, 4428, 4434, 4442, 4550, 4599, 4620, 4675, 4704, 4886, 4891, 4930, 5547, 5623, 5677, 5762, 5830, 5861, 5885, 6065, 6131, 6165, 6175, 6179, 6268, 6398, 6411, 6469, 6506, 6623, 6736, 6786, 6919, 6921, 6933, 6964, 6969, 7191, 7371, 7451, 7694, 7695, 7787, 8003, 8024, 8091, 8133, 8144, 8300, 8396, 9101, 9243, 9261, 9274, 9306, 9568, 9606, 9670, 9703, 9878, 172, 451, 602, 963, 1098, 1330, 1417, 1433, 1521, 1563, 1621, 1633, 1638, 1650, 1770, 1828, 1906, 1941, 1987, 2164, 2254, 2276, 2434, 2435, 2479, 2532, 2808, 2980, 3121, 3197, 3241, 3366, 3417, 3454, 3522, 3534, 3549, 3760, 3804, 3874, 4099, 4114, 4271, 4443, 4470, 4563, 4588, 4728, 4859, 4862, 4972, 5098, 5100, 5285, 5418, 5433, 5610, 5879, 5932, 6017, 6021, 6048, 6215, 6231, 6370, 6419, 6498, 6551, 6727, 6741, 6773, 7027, 7043, 7344, 7379, 7469, 7596, 7628, 7760, 7770, 7798, 7971, 8112, 8348, 8375, 8391, 8580, 8622, 8631, 8750, 8814, 8823, 8871, 8911, 9348, 9420, 9476, 9653, 9668, 9769};
  
  int n = sizeof(arr)/sizeof(arr[0]);
// table_size of hash table as 6
  HashMapTable ht(6);
  for (int i = 0; i < n; i++)
    ht.insertElement(arr[i]);
// deleting element 34 from the hash table
    //ht.deleteElement(34);
// displaying the final data of hash table
    ht.displayHashTable();
  return 0;
}