/*
 *  * Complete the function below.
 *   */
static void isPalindrome(string str) {
  if (String.IsNullOrEmpty(str)) {
    Console.WriteLine("false");
    return;

  }
  string tmp = new string(str.Reverse().ToArray());

  tmp = new string(tmp.Where(c => !char.IsPunctuation(c)).ToArray());
  str = new string(str.Where(c => !char.IsPunctuation(c)).ToArray());
  // tmp = tmp.ToLower();
  // str = str.ToLower();
  bool flag = false;
  for (int i = 0; i < str.Length; ++i) {
    if (str[i] != tmp[i]) {
      flag = true;
      break;
    }
  }
  if (flag) Console.WriteLine("true");
  else Console.WriteLine("false");        
}

