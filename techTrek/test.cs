// C#
// Checks to see if two strings are permutations
// Array version relies that the chars be encoded as ASCII
// made for practice interview
// Robert David Hernandez
// http://RobertHernandez.io/
// Dec 2015
//
/* "abba" "baab" -> true */
/* "no" "stuff" -> false */

using System;
using System.Text;

public static class MyClass {
  public static void Main(string[] args) {
    string first = "abba";
    string second = "baab";
    if (CheckString(first, second)) { Console.WriteLine("Success!"); }
    if (CheckStringArrayVersion(first, second)) { Console.WriteLine("Array Success!"); }
  }
  public static bool CheckString(string input_one, string input_two) {
    input_one = Alphabetize(input_one);
    input_two = Alphabetize(input_two);

    if (input_one.Length != input_two.Length) return false;

    for(int i = 0; i < input_one.Length; ++i) {
      if (input_one[i] != input_two[i]) return false;
    }
    return true;
  }
  public static bool CheckStringArrayVersion(string input_one, string input_two) {

    if (input_one.Length != input_two.Length) return false;

    int [] counter_one = new int[256];
    int [] counter_two = new int[256];


    for(int i = 0; i < input_one.Length; ++i) {
      counter_one [(int) input_one[i]]++;
    }
    for(int i = 0; i < input_two.Length; ++i) {
      counter_two [(int) input_two[i]]++;
    }

    for(int i = 0; i < 256; ++i) {
      if (counter_one[i] != counter_two[i]) return false;
    }
    return true;

  }


  /// <summary>
  /// Alphabetize the characters in the string.
  /// </summary>
  public static string Alphabetize(string s)    {
    // 1.
    // Convert to char array.
    char[] a = s.ToCharArray();

    // 2.
    // Sort letters.
    Array.Sort(a);

    // 3.
    // Return modified string.
    return new string(a);
  }

}
