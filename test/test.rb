require 'rconio'

def put_hr
    print "-" * 75
    print "\n"
end

def getch_pair (&block)
    c = yield
    fc = yield if RConio.kbhit != 0
    [ c, fc ]
end

puts "RConio test"

# Test RConio.getche
print "Input: "
input = getch_pair { RConio.getche }
puts "\n" + input.to_s + " " + input[0].chr

put_hr

# Test RConio.getche
print "Input (no echo): "
input_noecho = getch_pair { RConio.getch }
puts "\n" + input_noecho.to_s + " " + input_noecho[0].chr

put_hr

RConio.ungetch(input[0])
RConio.ungetch(input[1]) if input[1]
print "Input (unget first): "
input_ungot = getch_pair { RConio.getche }
puts "\n" + input_ungot.to_s

put_hr

print "Put char 'R': "
RConio.putch('R'.ord)
print "\n"

put_hr

print "Put string: "
RConio.cputs "Hello, World!"
print "\n"

put_hr

print "Get string (buffer size 80): "
input_string = RConio.cgets 80
puts input_string

put_hr

puts "Press Esc or 'Q' to exit."

chars = %w{ | / - \\ }
loop do
    print chars[0]
    sleep 0.1
    print "\b"

    chars.push chars.shift

    if RConio.kbhit == 1
        pair = getch_pair { RConio.getch }
        chr = pair[0].chr
        puts "input: #{pair.to_s} #{chr}"
        break if pair[0] == 27 || chr == 'Q' || chr == 'q'
    end
end

puts "done"
