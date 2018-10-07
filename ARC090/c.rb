n = gets.to_i
a1 = gets.split.map(&:to_i)
a2 = gets.split.map(&:to_i)

n.times do |i|
  next if i.zero?
  a1[i] += a1[i - 1]
  a2[i] += a2[i - 1]
end

max = 0
n.times do |i|
  if i.zero?
    max = a1[0] + a2[-1]
  else
    cand = a1[i] + a2[-1] - a2[i - 1]
    max = cand if max < cand
  end
end

p max
