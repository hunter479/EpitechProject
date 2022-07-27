import React from 'react';
import { withStyles } from '@material-ui/core/styles';
import { Menu, MenuItem, ListItemText, ListItemIcon } from '@material-ui/core';

const StyledMenu = withStyles({
    paper: {
        border: '1px solid #d3d4d5',
    },
  })(props => (
    <Menu
      elevation={0}
      getContentAnchorEl={null}
      anchorOrigin={{
        vertical: 'bottom',
        horizontal: 'center',
      }}
      transformOrigin={{
        vertical: 'top',
        horizontal: 'center',
      }}
      {...props}
    />
  ));

  const StyledMenuItem = withStyles(theme => ({
    root: {
      '&:focus': {
        backgroundColor: theme.palette.primary.main,
        '& .MuiListItemIcon-root, & .MuiListItemText-primary': {
          color: theme.palette.common.white,
        },
      },
    },
  }))(MenuItem);

function MenuManager(props) {
  const names = props.names;
  const actions = props.actions;
  const icons = props.icons;
  return (
    <StyledMenu
      id="customized-menu"
      anchorEl={props.anchorEl}
      keepMounted
      open={Boolean(props.anchorEl)}
      onClose={props.handleClose}>
      {names.map(function(name, index) {
          return (
              <StyledMenuItem onClick={actions[index]}>
                <ListItemIcon>
                  {icons[index]}
                </ListItemIcon>
                <ListItemText primary={name}/>
              </StyledMenuItem>
          );
      })
    }
    </StyledMenu>
  );
}

export default MenuManager;