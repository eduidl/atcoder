# http://agc016.contest.atcoder.jp/tasks/agc016_a
#
# submitted code

# def acount(array, char, count)
#   return Float::INFINITY if count > $min
#   return count if array.all? { |a| a == char }
#   n = array.size
#   new_array = []
#   (n-1).times do |i|
#     b = (array[i] == char || array[i+1] == char) ? char : array[i+1]
#     new_array << b
#   end
#   return acount(new_array, char, count + 1)
# end
#
# s = gets.chomp().split("")
# a = s.uniq
# $min = s.size
# a.each do |char|
#   candidate = acount(s, char, 0)
#   $min = candidate if $min > candidate
#   break if $min == 0
# end
# puts $min

# refactored code

def change_times(arr, char)
  return 0 if arr.all? { |a| a == char }
  new_arr = (0..(arr.size - 2)).to_a.map { |i| arr[i, 2].include?(char) ? char : nil }
  change_times(new_arr, char) + 1
end

char_arr = gets.chomp.split('')
puts char_arr.uniq.map { |char| change_times(char_arr, char) }.min