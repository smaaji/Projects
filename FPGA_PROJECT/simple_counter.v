module counter_main(clk, reset, enable, counter);
input clk, reset, enable;
output [23:0] counter; // counter output
reg [23:0] counter;

always @(posedge (clk),posedge (reset)) // always at positive edge 
	begin

		if(reset==1'b1)
			counter = 24'd0; // if reset counter output set to zero

		else 
			begin 
			if(enable==1'b1)
				counter = counter +1; // increment counterif sw1 is pressed
			else
				counter = counter - 1; //else reverse 
		end
		
	end
endmodule
