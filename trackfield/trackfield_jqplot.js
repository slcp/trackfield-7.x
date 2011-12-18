$(document).ready(function(){
  $('.trackfield').each(function(){
    var id = $(this).attr('id');
    var args = $(this).children('.args').html();
    trackgraph(id, args);
  });
});
  
function trackgraph(id, args) {
  $('#' + id).html('');
  dataurl = Drupal.settings.trackfield_graph.JqplotDataUrl + "/" + args;

  $.getJSON(dataurl, function(data){
    $.jqplot.config.enablePlugins = true;
    $.jqplot(id, data.series, data.options);
  });
}
