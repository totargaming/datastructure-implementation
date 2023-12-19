def anagram(str1,str2):
    if len(str1) != len(str2): return False
    
    sorted_s1 = ''.join(sorted(str1))
    sorted_s2 = ''.join(sorted(str2))
    
    return True if sorted_s1 == sorted_s2 else False