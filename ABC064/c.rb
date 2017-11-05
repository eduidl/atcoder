# http://abc064.contest.atcoder.jp/tasks/abc064_c

# submitted code

# N = gets.to_i
# a = gets.split(" ").map(&:to_i)
# b = Array.new(8, false)
# freecount = 0
# N.times do |i|
#   color = a[i] / 400
#   if (color < 8)
#     b[color] = true
#   else
#     freecount += 1
#   end
# end
#
# if b.count(true) != 0
#   min = b.count(true)
#   max = min + freecount
# else
#   min = 1
#   max = freecount
# end
#
# puts "#{min} #{max}"

# refactored code
gets
colors_map = gets.split.map { |a| [a.to_i / 400, 8].min }.each_with_object(Array.new(9, 0)) do |rank, arr|
  if rank == 8
    arr[rank] += 1
  else
    arr[rank] = 1
  end
end

max = colors_map.inject(:+)
min = [colors_map[0..7].inject(:+), 1].max
puts "#{min} #{max}"
