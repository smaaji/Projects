module clock_dvider(sw, clk, reset, out_clk);

input clk,reset,sw;
output out_clk;
reg out_clk,out_clk_aux;
reg [27:0]counter;

integer speed = 28'd50000000;

always @(posedge (clk),posedge (reset))
	begin

		if(reset==1'b1)
			begin
			counter = 28'd0;
			out_clk_aux=1'b0;
			end
		
		else if (sw ==1'b0)
			begin 
				if(counter>=28'd0 && counter<speed/2) // counter btwn 0 and 25 Million binary 
					begin
						out_clk_aux=1'b1;						// rising edge 
						counter = counter +1;				// increment 
					end
				else if (counter>=speed/2 && counter<speed) // counter btwn 12.5 million and 25 million  
					begin
						out_clk_aux=1'b0;						//falling edge 
						counter = counter +1;				//increment 
					end
					
				else
					begin
						counter = 28'd0;
					end
			end
			
			else if (sw ==1'b1)
			begin 
				if(counter>=28'd0 && counter<speed/4) // counter btwn 0 and 12.5 Million binary 
					begin
						out_clk_aux=1'b1;						// rising edge 
						counter = counter +1;				// increment 
					end
				else if (counter>=speed/4 && counter<speed/2) // counter btwn 12.5 million and 25 million  
					begin
						out_clk_aux=1'b0;						//falling edge 
						counter = counter +1;				//increment 
					end
				else if (counter>=speed/2 && counter<3*speed/4) // counter btwn 12.5 million and 25 million  
					begin
						out_clk_aux=1'b1;						//falling edge 
						counter = counter +1;				//increment 
					end
					else if (counter>= 3*speed/4 && counter<speed) // counter btwn 12.5 million and 25 million  
					begin
						out_clk_aux=1'b0;						//falling edge 
						counter = counter +1;				//increment 
					end
		
				else
					begin
						counter = 28'd0;
					end
			end
		// port assignements
		out_clk=out_clk_aux;
	end
endmodule


