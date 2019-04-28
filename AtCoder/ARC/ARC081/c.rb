# http://arc081.contest.atcoder.jp/tasks/arc076_a

# submitted code

# n = gets.to_i
# a = gets.split(" ").map(&:to_i)
#
# ret = {}
# b = []
# a.each do |i|
#   if ret[i].nil?
#     ret[i] = 1
#   elsif ret[i] == 1 || ret[i] == 3
#     b << i
#     ret[i] += 1
#   else
#     ret[i] += 1
#   end
# end
#
# if b.size <= 1
#   puts 0
# else
#   b.sort!
#   puts b[-2] * b[-1]
# end

# refactored code

def square(a)
  length_candidates = a.group_by(&:itself).each_with_object([]) do |(k, v), arr|
    [v.size / 2, 2].min.times { arr << k }
  end
  return 0 if length_candidates.size < 2
  length_candidates.sort[-2..-1].inject(:*)
end

gets
p square(gets.split.map(&:to_i))
