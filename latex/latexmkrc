# This registers a custom dependency: when LaTeX creates or updates a .idx file, latexmk should create the corresponding .ind file by calling the function named makeindex.
add_cus_dep('idx', 'ind', 0, 'makeindex');

# This defines a function. $_[0] is the document’s filename without its extension (e.g. for example, main from main.tex) so the command runs makeindex on main.idx, using indexstyle.ist to format the output. 
# MakeIndex then writes main.ind.
sub makeindex {
  my $base = $_[0];
  return system("makeindex -s indexstyle.ist \"$base.idx\"");
}

# The build sequence is:
    # 1. LaTeX writes the heading entries to main.idx.
    # 2. latexmk runs the custom MakeIndex command, producing main.ind.
    # 3. LaTeX runs again and inputs main.ind where the \IfFileExists command appears—after the title page in this setup.