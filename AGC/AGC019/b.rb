# http://agc019.contest.atcoder.jp/tasks/agc019_a

# submitted code

# def answer(a, l)
#   return 1 if l == 1
#   ans = 0
#   ret = {}
#   count = 0
#   a.each_with_index do |aa, i|
#     if ret.key? aa
#       ret[aa] += 1
#     else
#       ret[aa] = 1
#     end
#     if i == 0
#       ans = 1
#       count = 1
#     else
#       count += 1
#       ans += count - ret[aa]
#     end
#   end
#   return ans
# end
#
# a = gets.chomp.split(//)
# l = a.size
# p answer(a, l)

# refactored code

def answer(a)
  char_count = {}
  a.each_with_index.inject(1) do |ans, (aa, i)|
    char_count[aa] ||= 0
    char_count[aa] += 1
    ans + i - char_count[aa] + 1
  end
end

p answer(gets.chomp.split(//))
