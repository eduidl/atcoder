# http://agc016.contest.atcoder.jp/tasks/agc016_b

# submitted code

# N = gets.to_i
# get = "3 3 3 3 3"
# a = gets.split(" ").map(&:to_i)
#
# max = a.max
# min_count = 0
# kekka = true
#
# N.times do |i|
#   kekka = false if a[i] < max - 1
#   min_count += 1 if a[i] == max - 1
# end
#
# if kekka
#   if 2 * max - min_count > N
#     kekka = false
#   elsif min_count >= max
#     kekka = false
#   end
# end
#
# kekka = true if a.all? { |item| item == N - 1 }
#
# if kekka
#   puts "Yes"
# else
#   puts "No"
# end

# refactored code

def exist?(n, a)
  return true if a.all? { |num| num == n - 1 }
  color_count = a.max
  uniq_color_count = 0

  a.each do |num|
    return false if num < color_count - 1
    uniq_color_count += 1 if num == color_count - 1
  end

  multi_color_count = color_count - uniq_color_count
  return true if multi_color_count.positive? && 2 * multi_color_count + uniq_color_count <= n
  false
end

n = gets.to_i
a = gets.split.map(&:to_i)
puts exist?(n, a) ? 'Yes' : 'No'