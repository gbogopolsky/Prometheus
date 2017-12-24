#!/bin/bash

set -e

ruby -e "
left  = %x(git log --graph --oneline --decorate --date-order $1 --color=always).lines
right = %x(git log --graph --oneline --decorate --date-order $1 --pretty=format:'%C(bold green)(%cr)%C(reset) %C(bold cyan)<%an>%C(reset)').lines
puts left.zip(right).map { |l, r| %Q(#{l.chop} #{r[/^[\s\*\\\|\/_]*(.*)$/, 1]}) }
" | less -R
