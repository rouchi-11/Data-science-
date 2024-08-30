def count_words(filename):
    try:
        with open(filename, 'r') as file:
            content = file.read()
            words = content.split()
            word_count = len(words)
            
            return word_count
    except FileNotFoundError:
        print(f"File '{filename}' not found.")
        return 0


file_path = 'no_of_words_count.txt'

total_words = count_words(file_path)

print("Total number of words in the file: {}".format(total_words))
