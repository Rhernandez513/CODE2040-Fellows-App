using System;
using System.IO;

using System.Collections.Generic;
using System.Linq;
class Solution {

  static void IPWrapper(string input) {
    bool test1 = CheckIPv4(input);
    bool test2 = CheckIPv6(input);
    if (test1) {
      Console.WriteLine("IPv4");
    } else if (test2) {
      Console.WriteLine("IPv6");
    } else {
      Console.WriteLine("Neither");
    }
  }
  static void IPAddressValidator() {
    string input = Console.ReadLine();
    int tmp = 0;
    
    if (!int.TryParse(input, out tmp)) {
      Console.WriteLine("Fatal Error, Incorrect Input on first line.");
      return;
    }
    while (tmp > 0) {
      IPWrapper(Console.ReadLine());
      --tmp;
    }
  }

  static bool CheckIPv4(string input) {
    if (!input.Contains(".")) return false;
    if (input.Contains(" ")) return false;
    char [] delims = { '.' };
    string [] contents = input.Split(delims, 4, System.StringSplitOptions.RemoveEmptyEntries);
    for (int i = 0; i < contents.Length; ++i) {
      int tmp;
      bool test = int.TryParse(contents[i], out tmp);
      if (!test) { return test; }
      if (tmp > 255 || tmp < 0) { return false;  }
    }
    return true;
  }

  static bool CheckIPv6(string input) {
    if (!input.Contains(":")) { return false; }
    if (input.Contains(" ")) { return false; }
    bool hexflag = true;
    char [] delims = { ':' } ;
    char [] hexchars = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                         'a', 'b', 'c', 'd', 'e', 'f'
                       };
    string [] contents = input.Split(delims, 8, System.StringSplitOptions.RemoveEmptyEntries);
    // Compare each string in group of strings
    foreach (string s in contents) {
      // Compare each char in string
      foreach (char c in s) {
        // Compare each char in hexchars
        int count = 0;
        for(int i = 0; i < 16; ++i) {
          if (c != hexchars[i]) { count++; }
          if (count == 16) {
            hexflag = false; // Non-hex character in string -> Not a IPv6
            break;
          }
        }
        if (!hexflag) { return hexflag; } // char triggered flag, NOT IPv6 (returns false)
      }
    }
    return hexflag; // flag remained true -> YES IPv6
  }

  static void Main(string[] args) {
    IPAddressValidator();
  }
}

