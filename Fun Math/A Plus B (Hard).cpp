#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string a, b, result;

bool smaller(string a, string b)
{
  int aSize = a.length(), bSize = b.length();

  if (aSize < bSize)
  {
    return true;
  }
  else if (aSize > bSize)
  {
    return false;
  }
  else
  {
    for (int i = 0; i < aSize; ++i)
    {
      if (a[i] < b[i])
      {
        return true;
      }
      else if (a[i] > b[i])
      {
        return false;
      }
    }

    return false;
  }
}

string difference(string a, string b)
{
  if (smaller(a, b))
  {
    swap(a, b);
  }

  int aSize = a.length(), bSize = b.length();
  int difference = aSize - bSize;
  string result = "";
  int carry = 0;
  int subtraction;

  for (int i = b.length() - 1; i >= 0; --i)
  {
    subtraction = ((a[i + difference]-'0') - (b[i]-'0') - carry);

    if (subtraction < 0)
    {
      subtraction += 10;
      carry = 1;
    }
    else
    {
      carry = 0;
    }

    result.push_back(subtraction + '0');
  }

  for (int i = aSize - bSize - 1; i >= 0; --i)
  {
    if (a[i] == '0' && carry > 0)
    {
      result.push_back('9');
      continue;
    }

    subtraction = ((a[i]-'0') - carry);

    if (i > 0 || subtraction > 0)
    {
      result.push_back(subtraction +'0');
    }

    carry = 0;
  }

  reverse(result.begin(), result.end());
  
  return result;
}

string findDiff(string str1, string str2) 
{ 
    // Before proceeding further, make sure str1 
    // is not smaller 
    if (smaller(str1, str2)) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n1 - n2; 
  
    // Initially take carry zero 
    int carry = 0; 
  
    // Traverse from end of both strings 
    for (int i=n2-1; i>=0; i--) 
    { 
        // Do school mathematics, compute difference of 
        // current digits and carry 
        int sub = ((str1[i+diff]-'0') - 
                   (str2[i]-'0') - 
                   carry); 
        if (sub < 0) 
        { 
            sub = sub+10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of str1[] 
    for (int i=n1-n2-1; i>=0; i--) 
    { 
        if (str1[i]=='0' && carry) 
        { 
            str.push_back('9'); 
            continue; 
        } 
        int sub = ((str1[i]-'0') - carry); 
        if (i>0 || sub>0) // remove preceding 0's 
            str.push_back(sub+'0'); 
        carry = 0; 
  
    } 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

string sum(string a, string b)
{
  if (a.length() > b.length())
  {
    swap(a, b);
  }

  string result = "";
  int aSize = a.length(), bSize = b.length();
  int sizeDifference = aSize - bSize;
  int carry = 0;
  int sum;

  for (int i = aSize - 1; i >= 0; --i)
  {
      sum = ((a[i]-'0') + (b[i + sizeDifference]-'0') + carry);
      result.push_back(sum % 10 + '0');
      carry = sum / 10;
  }

  for (int i = bSize - aSize - 1; i >= 0; --i)
  {
      sum = ((b[i] + '0') + carry);
      result.push_back(sum % 10 + '0');
      carry = sum / 10;
  }

  if (carry > 0)
  {
      result.push_back(carry + '0');
  }

  reverse(result.begin(), result.end());

  return result;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);    

  int n = 0;
  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    cin >> a >> b;

    if (a[0] != '-' && b[0] != '-')
    {
      result = sum(a, b);
    }
    else if (a[0] == '-' && b[0] == '-')
    {
      result = "-" + sum(a.substr(1), b.substr(1));
    }
    else if (a[0] == '-')
    {
      if (smaller(a.substr(1), b))
      {
        result = difference(a.substr(1), b);
      }
      else
      {
        result = "-" + difference(a.substr(1), b);
      }
    }
    else
    {
      if (smaller(b.substr(1), a))
      {
        result = difference(a, b.substr(1));
      }
      else
      {
        result = "-" + difference(a, b.substr(1));
      }
    }

  if (result[0] == '0')
  {
    result = result.substr(1);
  }

  if (result[0] == '-' && result[1] == '0' && result.length() > 2)
  {
    result = "-" + result.substr(2);
  }

  if (result == "-0")
  {
    result = "0";
  }

    cout << result << "\n";
  }

}