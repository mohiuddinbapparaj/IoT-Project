buf = new Buffer(26);
for (var i = 0 ; i < 26 ; i++) {
  buf[i] = i + 97;
}
for (var j=1; j<27; j++){
	console.log( "0x" + buf.toString('hex',(j-1),j));
}