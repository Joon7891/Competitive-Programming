def encode(sentence):
  stored_words = sentence.split(' ')
  words = sentence.split(' ')
  return_words = [''] * len(words)
  char_array = []

  counter = -1 

  while len(words) > 0:

    counter = (counter + 1) % len(words)

    if (len(words[counter]) > 0):
      char_array.append(words[counter][0])
      words[counter] = words[counter][1:len(words[counter])]

    if len(words[counter]) == 0:
      words.remove(words[counter])   
      counter -= 1

  k = 0
  for i in range(len(stored_words)):
    for j in range(len(stored_words[i])):
      return_words[i] += char_array[k]
      k += 1
  
  final = str()
  for i in range(len(return_words)):
    if i + 1 != len(return_words):
      final += return_words[i] + " "
    else:
      final += return_words[i]

  return final

def decode(sentence):
  char_array = [char for char in sentence if char != ' ']
  words = sentence.split(' ')
  return_words = [''] * len(words)

  k = 0
  while k < len(char_array):
    for i in range(len(words)):
      if len(return_words[i]) < len(words[i]): 
        return_words[i] += char_array[k]
        k += 1
    
  final = str()
  for i in range(len(return_words)):
    if i + 1 != len(return_words):
      final += return_words[i] + " "
    else:
      final += return_words[i]

  return final
for i in range(10):
  selection = input()
  sentence = input()

  if selection == 'encode':
    print(encode(sentence))
  else:
    print(decode(sentence))