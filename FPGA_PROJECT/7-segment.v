
// Simple Verilog module for DE1-SoC that connects the SW switches to the LEDR lights
module Seven_Seg (clk, INP, HEX);
input [3:0] INP; // slide switches
input clk;
output [6:0] HEX; // red LEDs
reg [6:0] HEX;
always @(posedge clk)
begin
	case (INP)
		4'b0000 : HEX = 7'b1000000; // display 0
		4'b0001 : HEX = 7'b1111001; // display 1
		4'b0010 : HEX = 7'b0100100; // display 2
		4'b0011 : HEX = 7'b0110000; // display 3
		4'b0100 : HEX = 7'b0011001; // display 4
		4'b0101 : HEX = 7'b0010010; // display 5
		4'b0110 : HEX = 7'b0000010; // display 6
		4'b0111 : HEX = 7'b1111000; // display 7
		4'b1000 : HEX = 7'b0000000; // display 8
		4'b1001 : HEX = 7'b0010000; // display 9
		4'b1010 : HEX = 7'b0001000; // display a
		4'b1011 : HEX = 7'b0000011; // display b
		4'b1100 : HEX = 7'b1000110; // display c
		4'b1101 : HEX = 7'b0100001; // display d
		4'b1110 : HEX = 7'b0000110; // display e
		default : HEX = 7'b0001110; // display f
	endcase
end
endmodule
