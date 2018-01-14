n, a, b = gets.split.map(&:to_i)

if n == 2
  puts 'Borys'
elsif (a - b).odd?
  puts 'Borys'
else
  puts 'Alice'
end
