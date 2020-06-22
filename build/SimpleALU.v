module coreir_xor #(
    parameter width = 1
) (
    input [width-1:0] in0,
    input [width-1:0] in1,
    output [width-1:0] out
);
  assign out = in0 ^ in1;
endmodule

module coreir_sub #(
    parameter width = 1
) (
    input [width-1:0] in0,
    input [width-1:0] in1,
    output [width-1:0] out
);
  assign out = in0 - in1;
endmodule

module coreir_slice #(
    parameter hi = 1,
    parameter lo = 0,
    parameter width = 1
) (
    input [width-1:0] in,
    output [hi-lo-1:0] out
);
  assign out = in[hi-1:lo];
endmodule

module coreir_reg #(
    parameter width = 1,
    parameter clk_posedge = 1,
    parameter init = 1
) (
    input clk,
    input [width-1:0] in,
    output [width-1:0] out
);
  reg [width-1:0] outReg=init;
  wire real_clk;
  assign real_clk = clk_posedge ? clk : ~clk;
  always @(posedge real_clk) begin
    outReg <= in;
  end
  assign out = outReg;
endmodule

module coreir_mux #(
    parameter width = 1
) (
    input [width-1:0] in0,
    input [width-1:0] in1,
    input sel,
    output [width-1:0] out
);
  assign out = sel ? in1 : in0;
endmodule

module coreir_mul #(
    parameter width = 1
) (
    input [width-1:0] in0,
    input [width-1:0] in1,
    output [width-1:0] out
);
  assign out = in0 * in1;
endmodule

module coreir_add #(
    parameter width = 1
) (
    input [width-1:0] in0,
    input [width-1:0] in1,
    output [width-1:0] out
);
  assign out = in0 + in1;
endmodule

module commonlib_muxn__N2__width2 (
    input [1:0] in_data_0,
    input [1:0] in_data_1,
    input [0:0] in_sel,
    output [1:0] out
);
wire [1:0] _join_out;
coreir_mux #(
    .width(2)
) _join (
    .in0(in_data_0),
    .in1(in_data_1),
    .sel(in_sel[0]),
    .out(_join_out)
);
assign out = _join_out;
endmodule

module commonlib_muxn__N2__width16 (
    input [15:0] in_data_0,
    input [15:0] in_data_1,
    input [0:0] in_sel,
    output [15:0] out
);
wire [15:0] _join_out;
coreir_mux #(
    .width(16)
) _join (
    .in0(in_data_0),
    .in1(in_data_1),
    .sel(in_sel[0]),
    .out(_join_out)
);
assign out = _join_out;
endmodule

module commonlib_muxn__N4__width16 (
    input [15:0] in_data_0,
    input [15:0] in_data_1,
    input [15:0] in_data_2,
    input [15:0] in_data_3,
    input [1:0] in_sel,
    output [15:0] out
);
wire [15:0] _join_out;
wire [15:0] muxN_0_out;
wire [15:0] muxN_1_out;
wire [0:0] sel_slice0_out;
wire [0:0] sel_slice1_out;
coreir_mux #(
    .width(16)
) _join (
    .in0(muxN_0_out),
    .in1(muxN_1_out),
    .sel(in_sel[1]),
    .out(_join_out)
);
commonlib_muxn__N2__width16 muxN_0 (
    .in_data_0(in_data_0),
    .in_data_1(in_data_1),
    .in_sel(sel_slice0_out),
    .out(muxN_0_out)
);
commonlib_muxn__N2__width16 muxN_1 (
    .in_data_0(in_data_2),
    .in_data_1(in_data_3),
    .in_sel(sel_slice1_out),
    .out(muxN_1_out)
);
coreir_slice #(
    .hi(1),
    .lo(0),
    .width(2)
) sel_slice0 (
    .in(in_sel),
    .out(sel_slice0_out)
);
coreir_slice #(
    .hi(1),
    .lo(0),
    .width(2)
) sel_slice1 (
    .in(in_sel),
    .out(sel_slice1_out)
);
assign out = _join_out;
endmodule

module Mux4xOutUInt16 (
    input [15:0] I0,
    input [15:0] I1,
    input [15:0] I2,
    input [15:0] I3,
    input [1:0] S,
    output [15:0] O
);
wire [15:0] coreir_commonlib_mux4x16_inst0_out;
commonlib_muxn__N4__width16 coreir_commonlib_mux4x16_inst0 (
    .in_data_0(I0),
    .in_data_1(I1),
    .in_data_2(I2),
    .in_data_3(I3),
    .in_sel(S),
    .out(coreir_commonlib_mux4x16_inst0_out)
);
assign O = coreir_commonlib_mux4x16_inst0_out;
endmodule

module Mux2xOutBits2 (
    input [1:0] I0,
    input [1:0] I1,
    input S,
    output [1:0] O
);
wire [1:0] coreir_commonlib_mux2x2_inst0_out;
commonlib_muxn__N2__width2 coreir_commonlib_mux2x2_inst0 (
    .in_data_0(I0),
    .in_data_1(I1),
    .in_sel(S),
    .out(coreir_commonlib_mux2x2_inst0_out)
);
assign O = coreir_commonlib_mux2x2_inst0_out;
endmodule

module Register_has_ce_True_has_reset_False_has_async_reset_False_has_async_resetn_False_type_Bits_n_2 (
    input [1:0] I,
    output [1:0] O,
    input CLK,
    input CE
);
wire [1:0] enable_mux_O;
wire [1:0] value_out;
Mux2xOutBits2 enable_mux (
    .I0(value_out),
    .I1(I),
    .S(CE),
    .O(enable_mux_O)
);
coreir_reg #(
    .clk_posedge(1'b1),
    .init(2'h0),
    .width(2)
) value (
    .clk(CLK),
    .in(enable_mux_O),
    .out(value_out)
);
assign O = value_out;
endmodule

module ConfigReg (
    input [1:0] D,
    output [1:0] Q,
    input CLK,
    input CE
);
wire [1:0] conf_reg_O;
Register_has_ce_True_has_reset_False_has_async_reset_False_has_async_resetn_False_type_Bits_n_2 conf_reg (
    .I(D),
    .O(conf_reg_O),
    .CLK(CLK),
    .CE(CE)
);
assign Q = conf_reg_O;
endmodule

module SimpleALU (
    input [15:0] a,
    input [15:0] b,
    output [15:0] c,
    input [1:0] config_data,
    input config_en,
    input CLK
);
wire [15:0] Mux4xOutUInt16_inst0_O;
wire [1:0] config_reg_Q;
wire [15:0] magma_Bits_16_add_inst0_out;
wire [15:0] magma_Bits_16_mul_inst0_out;
wire [15:0] magma_Bits_16_sub_inst0_out;
wire [15:0] magma_Bits_16_xor_inst0_out;
Mux4xOutUInt16 Mux4xOutUInt16_inst0 (
    .I0(magma_Bits_16_add_inst0_out),
    .I1(magma_Bits_16_sub_inst0_out),
    .I2(magma_Bits_16_mul_inst0_out),
    .I3(magma_Bits_16_xor_inst0_out),
    .S(config_reg_Q),
    .O(Mux4xOutUInt16_inst0_O)
);
ConfigReg config_reg (
    .D(config_data),
    .Q(config_reg_Q),
    .CLK(CLK),
    .CE(config_en)
);
coreir_add #(
    .width(16)
) magma_Bits_16_add_inst0 (
    .in0(a),
    .in1(b),
    .out(magma_Bits_16_add_inst0_out)
);
coreir_mul #(
    .width(16)
) magma_Bits_16_mul_inst0 (
    .in0(a),
    .in1(b),
    .out(magma_Bits_16_mul_inst0_out)
);
coreir_sub #(
    .width(16)
) magma_Bits_16_sub_inst0 (
    .in0(a),
    .in1(b),
    .out(magma_Bits_16_sub_inst0_out)
);
coreir_xor #(
    .width(16)
) magma_Bits_16_xor_inst0 (
    .in0(a),
    .in1(b),
    .out(magma_Bits_16_xor_inst0_out)
);
assign c = Mux4xOutUInt16_inst0_O;
endmodule

