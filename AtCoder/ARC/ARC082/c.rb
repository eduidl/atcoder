# http://arc082.contest.atcoder.jp/tasks/arc082_a

# submitted code

# n = gets.to_i
# a = gets.split.map(&:to_i)
#
# h = {}
# a.each do |aa|
#   (-1..1).each do |d|
#     if h[aa + d].nil?
#       h[aa + d] = 1
#     else
#       h[aa + d] += 1
#     end
#   end
# end
#
# p h.values.max

# refactored code

def answer(a)
  num_count = a.each_with_object({}) do |aa, h|
    (-1..1).each do |d|
      h[aa + d] ||= 0
      h[aa + d] += 1
    end
  end
  num_count.values.max
end

gets
p answer(gets.split.map(&:to_i))
