# http://agc019.contest.atcoder.jp/tasks/agc019_a

# submitted code

# q, h, s, d = gets.split(" ").map(&:to_i)
# n = gets.to_i
#
# min = Float::INFINITY
# min_i = nil
# min2 = Float::INFINITY
# min2_i = nil
# a = [q * 4, h * 2, s, d / 2.0]
# a.each_with_index do |i, j|
#   if i < min
#     min2 = min
#     min2_i = min_i
#     min = i
#     min_i = j
#   elsif i < min2
#     min2 = i
#     min2_i = j
#   end
# end
#
# if min_i == 3
#   p (n / 2 * d + n % 2 * min2).to_i
# else
#   p (n * min).to_i
# end

# refactored code

q, h, s, d = gets.split.map(&:to_i)
n = gets.to_i
one_liter_min = [q * 4, h * 2, s].min
p n / 2 * [one_liter_min * 2, d].min + n % 2 * one_liter_min
