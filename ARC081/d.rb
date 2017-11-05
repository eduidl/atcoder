# http://arc081.contest.atcoder.jp/tasks/arc076_b

# submitted code

# def answer(s, last)
#   return 1 if s.size == 0
#   if s.size >= 2 && s[-1] == s[-2]
#     a = s.pop
#     a = s.pop
#     return answer(s, 2) * 3 % 1000000007 if last == 2
#     return answer(s, 2) * 2 % 1000000007 if last == 1
#     return answer(s, 2) * 6 % 1000000007 if last.nil?
#   else
#     a = s.pop
#     return answer(s, 1) % 1000000007 if last == 2
#     return answer(s, 1) * 2 % 1000000007 if last == 1
#     return answer(s, 1) * 3 % 1000000007 if last.nil?
#   end
# end
#
# N = gets.to_i
# s = gets.chomp.split(//)
# a = gets
# p answer(s, nil)

# refactored code

MODULO_BY = 1000000007

def answer(s, last)
  return 1 if s.empty?
  if s.size >= 2 && s[-1] == s[-2]
    product_num =
      case
      when last.nil?
        6
      when last == 1
        2
      when last == 2
        3
      end
    answer(s[0..-3], 2) * product_num % MODULO_BY
  else
    product_num =
      case
      when last.nil?
        3
      when last == 1
        2
      when last == 2
        1
      end
    answer(s[0..-2], 1) * product_num % MODULO_BY
  end
end

gets
s = gets.chomp.split(//)
gets
p answer(s, nil)

