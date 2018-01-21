def answer(t, x, y)
  n = t.size - 1
  n.times.with_index(1) do |i|
    time = t[i + 1] - t[i]
    distance = x[i + 1] - x[i] + y[i + 1] - y[i]
    return 'No' unless distance <=  time && (distance - time).even?
  end
  'Yes'
end

n = gets.to_i
t, x, y = [0], [0], [0]
n.times do |i|
  t[i + 1], x[i + 1], y[i + 1] = gets.split.map(&:to_i)
end

puts answer(t, x, y)