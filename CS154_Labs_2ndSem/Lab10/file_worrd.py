fl=open(sys.argv[1], 'r').readlines()
word_list=[lines.split(" ") for lines in fl]
print(len(word_list))
